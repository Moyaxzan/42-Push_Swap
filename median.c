/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:21:29 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/07/27 18:00:43 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *array, int len)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < len - 1)
	{
		while (k < len - j - 1)
		{
			if (array[k] > array[k + 1])
			{
				array[k] = array[k + 1] + array[k];
				array[k + 1] = array[k] - array[k + 1];
				array[k] = array[k] - array[k + 1];
			}
			k++;
		}
		j++;
	}
}

#include <stdio.h>
int	get_median(t_list *stack)
{
	int		length;
	t_list	*current;
	int		*array;
	int		i;
	int		res;

	length = ft_lstsize(stack);
	array = (int *) malloc(length * sizeof(int));
	current = stack;
	if (!array)
		return (0);
	i = 0;
	while (current)
	{
		array[i] = *((int *)(current->content));
		current = current->next;
		i++;
	}
	sort_array(array, length);
	res = array[length / 2];
	free(array);
	return (res);
}

static int	full_big(t_list *stack, int median)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (*((int *) current->content) < median)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	median;

	median = get_median(*stack_a);
	while (ft_lstsize(*stack_a) != 5)
	{
		while (!full_big(*stack_a, median)
			&& *((int *)(*stack_a)->content) >= median)
		{
			revert(stack_a);
			write(1, "ra\n", 3);
		}
		pb(stack_a, stack_b);
	}
}
