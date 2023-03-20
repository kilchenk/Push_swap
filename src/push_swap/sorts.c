/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:38:56 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/20 20:51:52 by kilchenk         ###   ########.fr       */
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
	if (get_size(a) == 5)
		push_pb(a, b, 1);
	push_pb(a, b, 1);
	if (!check_sorted(a))
		three_sort(a);
	if (get_size(b) == 2 && !check_sorted(b))
		swap_sb(b, 1);
	while ((*b) != NULL)
	{
		if ((*b)->value < (*a)->value)
			push_pa(a, b, 1);
		else if ((*b)->value > check_max_value(a))
		{
			while ((*a)->value != check_min_value(a))
				rotate_ra(a, 1);
			push_pa(a, b, 1);
		}
		else
			rotate_ra(a, 1);
	}
	while (!check_sorted(a))
		rotate_ra(a, 1);
}
