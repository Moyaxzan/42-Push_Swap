/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:22:54 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/09 14:26:23 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size <= 5)
		sort_five(stack_a, stack_b);
}
