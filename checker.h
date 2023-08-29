/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:45:47 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/18 11:55:02 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

char	**new_split(int argc, char **argv);
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
int		free_split(char **splitted_tab);

//void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
