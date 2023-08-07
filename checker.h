/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:45:47 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/04 18:06:53 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	**free_split(char **splitted_tab);
char	**new_split(int argc, char **argv);
void	sort(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b, int i_write);
void	pb(t_list **stack_a, t_list **stack_b, int i_write);
void	revert(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrevert(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	free_content(void *content);
int		init(char **argv, t_list **stack_a);
int		is_sorted(t_list *stack);
int		check(t_list **stack_a, t_list **stack_b);

void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
