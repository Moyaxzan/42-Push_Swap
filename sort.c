/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:22:54 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/17 11:54:28 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_above_med(t_list *stack_a, int min)
{
	t_list	*current;

	current = stack_a;
	init_costs(stack_a);
	while (current && *((int *)(current->content)) != min)
		current = current->next;
	return (current->above_median);
}

static void	small_actions(t_list **stack_a,
		t_list **stack_b, t_list *node_a, t_list *node_b)
{
	if (node_a != *stack_a && node_a->above_median)
	{
		revert(stack_a);
		write(1, "ra\n", 3);
	}
	else if (node_a != *stack_a)
	{
		rrevert(stack_a);
		write(1, "rra\n", 4);
	}
	if (node_b->above_median && node_b != *stack_b)
	{
		revert(stack_b);
		write(1, "rb\n", 3);
	}
	else if (node_b != *stack_b)
	{
		rrevert(stack_b);
		write(1, "rrb\n", 4);
	}
	return ;
}

void	bring_top(t_list **stack_a,
		t_list **stack_b, t_list *node_a, t_list *node_b)
{
	while (*stack_a != node_a && *stack_b != node_b)
	{
		if (node_a->above_median && node_b->above_median)
		{
			rr(stack_a, stack_b);
			write(1, "rr\n", 3);
		}
		else if (!node_a->above_median && !node_b->above_median)
		{
			rrr(stack_a, stack_b);
			write(1, "rrr\n", 4);
		}
		else
			break ;
	}
	while (*stack_a != node_a || *stack_b != node_b)
		small_actions(stack_a, stack_b, node_a, node_b);
	return ;
}

void	sort_huge(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_to_move;

	init_targets(*stack_a, *stack_b);
	node_to_move = get_cheapest_move(*stack_a, *stack_b);
	if (*stack_b)
	{
		bring_top(stack_a, stack_b, node_to_move->target, node_to_move);
		pa(stack_a, stack_b, 1);
	}
	if (!*stack_b  && stack_a && (*stack_a)->content)
	{
		while (*((int *)(*stack_a)->content) != min(*stack_a))
		{
			init_costs(*stack_a);
			if (min_above_med(*stack_a, min(*stack_a)))
			{
				revert(stack_a);
				write(1, "ra\n", 3);
			}
			else
			{
				rrevert(stack_a);
				write(1, "rra\n", 4);
			}
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2)
	{
		swap(stack_a);
		return ((void) write(1, "sa\n", 3));
	}
	if (stack_size == 3)
		return (sort_three(stack_a));
	else
	{
		push_to_b(stack_a, stack_b);
		stack_size = ft_lstsize(*stack_a);
		if (stack_size == 3)
			sort_three(stack_a);
		while (*stack_b || !is_sorted(*stack_a))
			sort_huge(stack_a, stack_b);
		//print_stacks(*stack_a, *stack_b);
	}
}
