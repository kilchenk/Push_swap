/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:00:20 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/13 19:03:29 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ab(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

static int	calculate_value(int a, int b)
{
	if ((a > 0 && b < 0 || a < 0 && b > 0))
		return (ab(a) + ab(b));
	else if (ab(a) > ab(b))
		return (ab(a));
	else
		return (ab(b));
}

int	check_rotate(t_transf_price *price, t_stack *a, t_stack *b)
{
	t_stack	*cur;
	int		low;
	int		i;

	low = 0;
	i = 0;
	cur = b;
	while (cur)
	{
		price[i].moves[0] = find_place(a, cur->value);
		price[i].moves[1] = min_rotations(b, cur->value);
		price[i].value = calculate_value(price[i].moves[0], \
			price[i].moves[1]);
		if (price[i].value < price[low].value)
			low = i;
		i++;
		cur = cur->next;
	}
	return (low);
}

void	double_rot(t_transf_price *price, t_stack **a, t_stack **b, int index)
{
	while (price[index].moves[0] > 0 && price[index].moves[1] > 0)
	{
		price[index].moves[0] -= 1;
		price[index].moves[1] -= 1;
		rotate_rr(a, b, 1);
	}
	while (price[index].moves[0] < 0 && price[index].moves[1] < 0)
	{
		price[index].moves[0] += 1;
		price[index].moves[1] += 1;
		rev_rot_rrr(a, b, 1);
	}
}

void	single_rot(t_transf_price *price, t_stack **a, t_stack **b, int index)
{
	while (price[index].moves[0] > 0)
	{
		price[index].moves[0] -= 1;
		rotate_ra(a, 1);
	}
	while (price[index].moves[1] > 0)
	{
		price[index].moves[1] -= 1;
		rotate_rb(b, 1);
	}
	while (price[index].moves[0] < 0)
	{
		price[index].moves[0] += 1;
		rev_rot_rra(a, 1);
	}
	while (price[index].moves[1] < 0)
	{
		price[index].moves[1] += 1;
		rev_rot_rrb(b, 1);
	}
}
