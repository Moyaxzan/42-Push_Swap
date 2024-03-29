/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:21:29 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/21 12:25:54 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

static void	sort_array(int *array, int size)
{
	int	min;
	int	imin;
	int	cpt1;
	int	cpt2;

	cpt1 = 0;
	while (cpt1 < size)
	{
		imin = cpt1;
		min = array[cpt1];
		cpt2 = cpt1 + 1 ;
		while (cpt2 < size)
		{
			if (array[cpt2] < min)
			{
				min = array[cpt2];
				imin = cpt2;
			}
			cpt2++;
		}
		ft_swap(&array[cpt1], &array[imin]);
		cpt1++;
	}
}

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

int	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	median;

	median = get_median(*stack_a);
	if (!median)
		return (0);
	while (ft_lstsize(*stack_a) != 3 && !only_target(*stack_a))
	{
		while (!full_big(*stack_a, median)
			&& *((int *)(*stack_a)->content) > median
			&& !only_target(*stack_a))
		{
			revert(stack_a);
			write(1, "ra\n", 3);
		}
		if (!only_target(*stack_a))
			pb(stack_a, stack_b, 1);
	}
	return (1);
}
