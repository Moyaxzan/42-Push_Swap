/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:42:13 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/04 19:22:09 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_target(t_list *stack_a, int val)
{
	t_list	*current_node;
	t_list	*target;
	int		target_val;

	current_node = stack_a;
	target = stack_a;
	target_val = max(stack_a);
	while (current_node)
	{
		if (*((int *)current_node->content) > val
			&& *((int *) current_node->content) <= target_val)
		{
			target = current_node;
			target_val = (*(int *)current_node->content);
		}
		current_node = current_node->next;
	}
	return (target);
}

static t_list	*get_min_node(t_list *stack)
{
	int		min;
	t_list	*min_ptr;

	if (!stack)
		return (0x0);
	min = *((int *)stack->content);
	min_ptr = stack;
	while (stack)
	{
		if (*((int *)stack->content) < min)
		{
			min = *((int *)stack->content);
			min_ptr = stack;
		}
		stack = stack->next;
	}
	return (min_ptr);
}

void	init_targets(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_node;

	if (!stack_a || !stack_b)
		return ;
	current_node = stack_b;
	while (current_node)
	{
		if (*((int *)current_node->content) > max(stack_a))
			current_node->target = get_min_node(stack_a);
		else
			current_node->target
				= get_target(stack_a, *((int *)current_node->content));
		current_node = current_node->next;
	}
}
