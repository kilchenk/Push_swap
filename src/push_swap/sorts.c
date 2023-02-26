/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:38:56 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/26 19:26:10 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	three_sort(t_stack	**s)
{
	if ((*s)->value > (*s)->next->value && \
		(*s)->value < (*s)->next->next->value)
		swap_sa(s, 1);
	else if ((*s)->value < (*s)->next->value && \
		(*s)->value > (*s)->next->next->value)
		rev_rot_rra(s, 1);
	else if ((*s)->value > (*s)->next->value && \
		(*s)->next->value < (*s)->next->next->value)
		rotate_ra(s, 1);
	else if ((*s)->value < (*s)->next->value && \
		(*s)->value < (*s)->next->next->value)
	{
		rev_rot_rra(s, 1);
		swap_sa(s, 1);
	}
	else if ((*s)->value > (*s)->next->value && \
		(*s)->next->value > (*s)->next->next->value)
	{
		rotate_ra(s, 1);
		swap_sa(s, 1);
	}
}

void	small_sort(t_stack **a, t_stack **b)
{

}
