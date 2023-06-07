/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:29:16 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/07 16:30:53 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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
	t_list	*node;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = 0;
	stack_b = 0;
	if (!init(argc, argv, &stack_a))
	{
		write(2, "Error\n", 5);
		return (-1);
	}
	//print_stacks(stack_a, stack_b);
	if (ft_lstsize(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	print_stacks(stack_a, stack_b);
	return (0);
}
