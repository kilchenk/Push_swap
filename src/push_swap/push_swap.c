/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:32:40 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/13 19:14:57 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../inc/push_swap.h"

void	push_back_sort(t_stack **a, t_stack **b)
{
	t_transf_price	*price;
	size_t			size;
	int				low;

	size = get_size(b);
	price = (t_transf_price *)malloc(sizeof(t_transf_price) * size);
	while ((*b) != 0)
	{
		low = check_rotate(price, *a, *b);
		double_rot(price, a, b, low);
		single_rot(price, a, b, low);
		push_pa(a, b, 1);
	}
	free(price);
}

void	push_mid_b(t_stack **a, t_stack **b)
{
	t_stack	*head;
	double	f;
	int		mid;

	head = *a;
	f = 0;
	while (head)
	{
		f += ((double)head->value / 1000);
		head = head->next;
	}
	mid = (f * 1000) / get_size(a);
	while (get_size(a) > 3)
	{
		if ((*a)->value <= mid)
		{
			push_pb(a, b, 1);
			rotate_rb(b, 1);
		}
		else
			push_pb(a, b, 1);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	rotates;

	push_pb(a, b, 1);
	push_pb(a, b, 1);
	push_mid_b(a, b);
	if (!check_sorted(a))
		three_sort(a);
	push_back_sort(a, b);
	rotates = min_rotations(*a, get_min(a));
	while (rotates != 0)
	{
		if (rotates < 0)
		{
			rev_rot_rra(a, 1);
			rotates++;
		}
		else
		{
			rotate_ra(a, 1);
			rotates--;
		}
	}
}

void	sort_type_check(t_stack **stack_a, t_stack **stack_b)
{
	if (get_size(stack_a) == 1)
		return ;
	else if (get_size(stack_a) == 2 && !check_sorted(stack_a))
		swap_sa(stack_a, 1);
	else if (get_size(stack_a) < 4 && !check_sorted(stack_a))
		three_sort(stack_a);
	else if (get_size(stack_a) <= 5 && !check_sorted(stack_a))
		small_sort(stack_a, stack_b);
	else if (get_size(stack_a) > 5 && !check_sorted(stack_a))
		push_swap(stack_a, stack_b);
}
