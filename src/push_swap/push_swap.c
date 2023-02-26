/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:32:40 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/26 19:23:16 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../inc/push_swap.h"

void	sort_type_check(t_stack **stack_a, t_stack **stack_b)
{
	if (get_size(stack_a) == 1)
		return ;
	else if (get_size(stack_a) == 2 && !check_sorted(stack_a))
		swap_sa(stack_a, 1);
	else if (get_size(stack_a) < 4 && !check_sorted(stack_a))
		three_sort(stack_a);
	else if (get_size(stack_a) <= 5 && !check_sorted(stack_a))
//need create any sort function and after put here
}
