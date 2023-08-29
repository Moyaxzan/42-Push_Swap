/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:49:15 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/29 12:22:18 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft/libft.h"

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
	if (argc == 1)
		return (-1);
	if (!init(new_split(argc, argv), &stack_a))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&stack_a, free_content);
		return (-1);
	}
	return (check(&stack_a, &stack_b));
}
