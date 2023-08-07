/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:29:16 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/07 12:24:06 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
}*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0x0;
	stack_b = 0x0;
	if (!init(new_split(argc, argv), &stack_a))
	{
		ft_lstclear(&stack_a, free_content);
		write(2, "Error\n", 6);
		return (-1);
	}
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
