/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:16:36 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/01 18:57:48 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cost(t_list *stack, int index)
{
	int	lst_len;

	lst_len = ft_lstsize(stack);
	if (index > lst_len / 2)
		return (index - lst_len + 1);
	return (index);
}

void	init_costs(t_list *stack_a, t_list *stack_b)
{
	t_list	*curr_node;
	int		index;

	index = 0;
	curr_node = stack_a;
	while (curr_node)
	{
		curr_node->cost = get_cost(stack_a, index++);
		if (curr_node->cost < 0)
		{
			curr_node->above_median = 0;
			curr_node->cost = -curr_node->cost;
		}
		else
			curr_node->above_median = 1;
		curr_node = curr_node->next;
	}
	index = 0;
	curr_node = stack_b;
	while (curr_node)
	{
		curr_node->cost = get_cost(stack_b, index++);
		curr_node = curr_node->next;
	}
}

t_list	*get_cheapest_move(t_list *stack_b)
{
	int		cheapest_cost;
	t_list	*cheapest_node;

	if (!stack_b)
		return (0x0);
	cheapest_cost = stack_b->cost + stack_b->target->cost;
	cheapest_node = stack_b;
	while (stack_b)
	{
		if (stack_b->cost + stack_b->target->cost < cheapest_cost)
		{
			cheapest_cost = stack_b->cost + stack_b->next->cost;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}
