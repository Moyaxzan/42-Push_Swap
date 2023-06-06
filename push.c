/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:04:03 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/06 14:20:16 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	write(1, "pa\n", 3);
	if (stack_b && *stack_b && stack_a)
	{
		tmp = *stack_b;
		(*stack_b) = tmp->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	write(1, "pb\n", 3);
	if (stack_a && *stack_a && stack_b)
	{
		tmp = *stack_a;
		(*stack_a) = tmp->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}
