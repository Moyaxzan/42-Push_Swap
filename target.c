/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:42:13 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/10 16:03:35 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_target(t_list *stack_a, int val)
{
	t_list	*current_node;

	current_node = stack_a;
	while (current_node)
	{
		if (*((int *)current_node->content) > val)
			return (current_node);
		current_node = current_node->next;
	}
	return (stack_a);
}

void	init_targets(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_node;

	if (!stack_a || !stack_b)
		return ;
	current_node = stack_b;
	while (current_node)
	{
		current_node->target
			= get_target(stack_a, *((int *)current_node->content));
		current_node = current_node->next;
	}
}
