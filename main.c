/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:29:16 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/01 18:51:05 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d", *((int *) stack_a->content));
			stack_a = stack_a->next;
		}
		else
			printf(" ");
		if (stack_b)
		{
			printf("\t%d", *((int *) stack_b->content));
			stack_b = stack_b->next;
		}
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0x0;
	stack_b = 0x0;
	if (!init(argc, argv, &stack_a))
	{
		write(2, "Error\n", 5);
		return (-1);
	}
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	return (0);
}
