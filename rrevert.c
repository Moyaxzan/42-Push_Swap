/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrevert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:26:37 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/05 13:43:08 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrevert(t_list **stack)
{
	t_list	*tmp;

	if (stack && *stack && (*stack)->next)
	{
		tmp = *stack;
		while ((*stack)->next->next)
			*stack = (*stack)->next;
		(*stack)->next->next = tmp;
		tmp = (*stack)->next;
		(*stack)->next = 0x0;
		*stack = tmp;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrevert(stack_a);
	rrevert(stack_b);
}
