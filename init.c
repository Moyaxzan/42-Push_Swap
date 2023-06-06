/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:58:20 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/06 13:03:45 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_isnum(const char *str_num)
{
	int	i;

	i = 0;
	if (str_num[i] == '-')
		i++;
	while (str_num[i] && ft_isdigit(str_num[i]))
		i++;
	if (!str_num[i] && i > 0 && str_num[i - 1] != '-')
		return (1);
	return (0);
}

int	check_dup(t_list *stack, int content)
{
	while (stack)
	{
		if (*((int *)stack->content) == content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	valid_input(int argc, char **argv)
{
	int		i;
	size_t	len;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			return (0);
		len = ft_strlen(argv[i]);
		if (len > 9)
		{
			if (len > 11)
				return (0);
			if (len == 10 && ft_strncmp(argv[i], "2147483647", len) > 0)
				return (0);
			if (len == 11 && ft_strncmp(argv[i], "-2147483648", len) > 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	init(int argc, char **argv, t_list **stack_a)
{
	int		i;
	int		*content;
	t_list	*new;

	i = 1;
	if (!valid_input(argc, argv))
		return (0);
	while (i < argc)
	{
		content = malloc(sizeof(int));
		//TODO if fail : free all
		if (!content)
			return (0);
		*content = ft_atoi(argv[i]);
		if (!check_dup(*stack_a, *content))
			return (0);
		new = ft_lstnew(content);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}
