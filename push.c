/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <tsaint-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:04:03 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/06/04 22:26:19 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **source_s, t_list **target_s)
{
	t_list	*tmp;

	if (source_s && *source_s && target_s)
	{
		tmp = *source_s;
		(*source_s) = tmp->next;
		tmp->next = *target_s;
		*target_s = tmp;
	}
}
