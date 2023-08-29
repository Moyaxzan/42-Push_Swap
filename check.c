/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:43:37 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/28 15:23:32 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft/Get-Next-Line/get_next_line.h"
#include <stdlib.h>

static int	apply_move(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		swap(stack_a);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		swap(stack_b);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		revert(stack_a);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		revert(stack_b);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rrevert(stack_a);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrevert(stack_b);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	check(t_list **stack_a, t_list **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (!apply_move(instruction, stack_a, stack_b))
		{
			ft_lstclear(stack_a, free);
			ft_lstclear(stack_b, free);
			free(instruction);
			get_next_line(-1);
			write(2, "Error\n", 6);
			return (-1);
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	if (!*stack_b && is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(stack_a, free);
	return (0);
}
