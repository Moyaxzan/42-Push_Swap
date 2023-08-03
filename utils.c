/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:02:27 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/03 19:17:12 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_content(void *content)
{
	free(content);
}

int	is_sorted(t_list *stack)
{
	int	prev;

	if (!stack)
		return (0);
	prev = *((int *)stack->content);
	stack = stack->next;
	while (stack)
	{
		if (*((int *)stack->content) < prev)
			return (0);
		prev = *((int *)stack->content);
		stack = stack->next;
	}
	return (1);
}

int	max(t_list *stack)
{
	int	max;

	max = *((int *) stack->content);
	while (stack)
	{
		if (max < *((int *) stack->content))
			max = *((int *) stack->content);
		stack = stack->next;
	}
	return (max);
}

int	min(t_list *stack)
{
	int	min;

	min = *((int *) stack->content);
	while (stack)
	{
		if (min > *((int *) stack->content))
			min = *((int *) stack->content);
		stack = stack->next;
	}
	return (min);
}
