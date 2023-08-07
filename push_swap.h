/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:45:47 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/08/07 12:24:46 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

t_list	*get_cheapest_move(t_list *stack_a, t_list *stack_b);
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
void	sort_three(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	free_content(void *content);
void	init_targets(t_list *stack_a, t_list *stack_b);
void	init_costs(t_list *stack);
void	push_to_b(t_list **stack_a, t_list **stack_b);
int		init(char **argv, t_list **stack_a);
int		max(t_list *stack);
int		min(t_list *stack);
int		is_sorted(t_list *stack);
int		get_median(t_list *stack);
int		free_split(char **splitted_tab);

//void	print_stacks(t_list *stack_a, t_list *stack_b);

#endif
