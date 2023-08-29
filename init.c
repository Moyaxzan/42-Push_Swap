/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:58:20 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/21 15:27:33 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(const char *str_num)
{
	int	i;

	i = 0;
	if (!ft_strncmp("+", str_num, 2))
		return (0);
	if (str_num[i] == '-' || str_num[i] == '+')
		i++;
	while (str_num[i] && ft_isdigit(str_num[i]))
		i++;
	if (!str_num[i] && i > 0 && str_num[i - 1] != '-')
		return (1);
	return (0);
}

static int	check_dup(t_list *stack, int content)
{
	while (stack)
	{
		if (*((int *)stack->content) == content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	valid_input(char **argv)
{
	int		i;
	size_t	len;

	i = 0;
	while (argv[i])
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
	if (!i)
		return (0);
	return (1);
}

int	init(char **argv, t_list **stack_a)
{
	int		i;
	int		*content;
	t_list	*new;

	i = 0;
	if (!valid_input(argv))
		return (free_split(argv));
	while (argv[i])
	{
		content = malloc(sizeof(int));
		if (!content)
			return (free_split(argv));
		*content = ft_atoi(argv[i++]);
		if (!check_dup(*stack_a, *content))
		{
			free(content);
			return (free_split(argv));
		}
		new = ft_lstnew(content);
		if (!new)
			return (free_split(argv));
		ft_lstadd_back(stack_a, new);
	}
	free_split(argv);
	return (1);
}
