/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:14:33 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/04 17:35:00 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revert(t_list **stack)
{
	t_list	*tmp;

	if (stack && *stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *stack;
		*stack = (*stack)->next;
		tmp->next->next = 0x0;
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	revert(stack_a);
	revert(stack_b);
}
