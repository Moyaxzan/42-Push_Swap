/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:41:19 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/21 12:30:50 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_target(t_list *stack_a)
{
	t_list	*current;

	init_targets(stack_a, stack_a);
	current = stack_a;
	while (current)
	{
		if (current->target != current->next && current->next)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	sort_three_p2(t_list **stack, int first, int second, int third)
{
	if (first > third)
	{
		rrevert(stack);
		return (write(1, "rra\n", 4));
	}
	else if (second > third)
	{
		swap(stack);
		revert(stack);
		return (write(1, "sa\nra\n", 6));
	}
	return (0);
}

int	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *((int *)(*stack)->content);
	second = *((int *)(*stack)->next->content);
	third = *((int *)(*stack)->next->next->content);
	if (first > second && second > third)
	{
		swap(stack);
		rrevert(stack);
		return (write(1, "sa\nrra\n", 7));
	}
	else if (first > second && first > third)
	{
		revert(stack);
		return (write(1, "ra\n", 3));
	}
	else if (first > second)
	{
		swap(stack);
		return (write(1, "sa\n", 3));
	}
	else
		return (sort_three_p2(stack, first, second, third));
}
