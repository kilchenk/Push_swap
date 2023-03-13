/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:05:23 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/11 18:05:13 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	min_rotations(t_stack *a, int value)
{
	t_stack	*cur;
	size_t	i;

	cur = a;
	i = 0;
	while (cur && cur->value != value)
	{
		cur = cur->next;
		i++;
	}
	if (get_size(&a) - i < i)
		return (i - get_size(&a));
	return (i);
}

int	find_place(t_stack *a, int value)
{
	t_stack	*cur;
	int		low;
	int		max;

	max = 1;
	cur = a;
	low = INT_MAX;
	while (cur)
	{
		if (cur->value > value && cur->value <= low)
		{
			max = 0;
			low = cur->value;
		}
		cur = cur->next;
	}
	if (max)
		low = get_min(&a);
	return (min_rotations(a, low));
}
