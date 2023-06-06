/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:41:19 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/06 14:46:04 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	sort_three_p2(t_list **stack, int first, int second, int third)
{
	if (first > third)
	{
		rrevert(stack);
		write(1, "rra\n", 4);
	}
	else if (second > third)
	{
		swap(stack);
		revert(stack);
		write(1, "sa\nra\n", 6);
	}
}

void	sort_three(t_list **stack)
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
		write(1, "sa\nrra\n", 7);
	}
	else if (first > second && first > third)
	{
		revert(stack);
		write(1, "ra\n", 3);
	}
	else if (first > second)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
	else
		sort_three_p2(stack, first, second, third);
}
