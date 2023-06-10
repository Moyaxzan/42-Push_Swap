/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:22:54 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/10 15:53:12 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	fix_a(t_list **stack_a, int b_top)
{
	while (*((int *)(*stack_a)->content) != min(*stack_a))
	{
		if (b_top)
		{
			rrevert(stack_a);
			write(1, "rra\n", 4);
		}
		else
		{
			revert(stack_a);
			write(1, "ra\n", 3);
		}
	}
}

static int	small_actions(t_list **stack_a,
		t_list **stack_b, t_list *node_a, t_list *node_b)
{
	int	res;

	res = 0;
	if (node_a != *stack_a && node_a->above_median)
	{
		revert(stack_a);
		write(1, "ra\n", 3);
		res = 1;
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
	return (res);
}

// return 0 if a rreverted and 1 if a reverted
int	bring_top(t_list **stack_a,
		t_list **stack_b, t_list *node_a, t_list *node_b)
{
	int	res;

	res = 0;
	while (*stack_a != node_a && *stack_b != node_b)
	{
		if (node_a->above_median && node_b->above_median)
		{
			rr(stack_a, stack_b);
			res = 1;
		}
		else if (!node_a->above_median && !node_b->above_median)
			rrr(stack_a, stack_b);
		else
			break ;
	}
	while (*stack_a != node_a || *stack_b != node_b)
		res = small_actions(stack_a, stack_b, node_a, node_b);
	return (res);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) != 5)
	{
		pb(stack_a, stack_b);
	}
}

void	sort_huge(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_to_move;
	int		b_top;

	init_targets(*stack_a, *stack_b);
	node_to_move = get_cheapest_move(*stack_b);
	b_top = bring_top(stack_a, stack_b, node_to_move->target, node_to_move);
	pa(stack_a, stack_b);
	fix_a(stack_a, b_top);
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
	if (stack_size <= 5)
		return (sort_five(stack_a, stack_b));
	else
	{
		push_to_b(stack_a, stack_b);
		sort_five(stack_a, stack_b);
		while (!is_sorted(*stack_a) || *stack_b)
			sort_huge(stack_a, stack_b);
	}
}
