/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:41:19 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/07 16:18:38 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

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

void	fix(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	third;

	first = *((int *)(*stack_a)->content);
	third = *((int *)(*stack_a)->next->next->content);
	if (first == max(*stack_a))
	{
		revert(stack_a);
		write(1, "ra\n", 3);
	}
	else if (first < third)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (first > *((int *)(*stack_a)->next->next->next->content))
	{
		rrevert(stack_a);
		swap(stack_a);
		revert(stack_a);
		revert(stack_a);
		write(1, "rra\nsa\nra\nra\n", 13);
	}
	else
	{
		swap(stack_a);
		write(1, "sa\n", 3);
		pb(stack_a, stack_b);
		swap(stack_a);
		write(1, "sa\n", 3);
		pa(stack_a, stack_b);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ; //return 0 ?
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		fix(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		fix(stack_a, stack_b);
}
