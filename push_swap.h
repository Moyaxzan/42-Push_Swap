/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:45:47 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/21 12:28:39 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*------------------------basic_sorts.c-------------------------*/
int		only_target(t_list *stack_a);
int		sort_three(t_list **stack);

/*----------------------------cost.c----------------------------*/
t_list	*get_cheapest_move(t_list *stack_a, t_list *stack_b);
void	init_costs(t_list *stack);

/*----------------------------init.c----------------------------*/
int		init(char **argv, t_list **stack_a);

/*---------------------------median.c---------------------------*/
int		get_median(t_list *stack);
int		push_to_b(t_list **stack_a, t_list **stack_b);

/*-------------------------new_split.c--------------------------*/
char	**new_split(int argc, char **argv);
int		free_split(char **splitted_tab);

/*---------------------------push.c-----------------------------*/
void	pa(t_list **stack_a, t_list **stack_b, int i_write);
void	pb(t_list **stack_a, t_list **stack_b, int i_write);

/*--------------------------revert.c----------------------------*/
void	revert(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);

/*--------------------------rrevert.c---------------------------*/
void	rrevert(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

/*----------------------------sort.c----------------------------*/
int		sort(t_list **stack_a, t_list **stack_b);

/*----------------------------swap.c----------------------------*/
void	swap(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);

/*--------------------------target.c----------------------------*/
void	init_targets(t_list *stack_a, t_list *stack_b);

/*---------------------------utils.c----------------------------*/
void	free_content(void *content);
int		max(t_list *stack);
int		min(t_list *stack);
int		is_sorted(t_list *stack);

//void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
