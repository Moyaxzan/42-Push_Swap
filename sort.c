/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:22:54 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/09 17:20:08 by tsaint-p         ###   ########.fr       */
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
		return ((void) write(1, "sa\n", 3));
	}
	if (stack_size == 3)
		return (sort_three(stack_a));
	if (stack_size <= 5)
		return (sort_five(stack_a, stack_b));

}
