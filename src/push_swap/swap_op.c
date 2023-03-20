/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:36:24 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/20 20:52:06 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../inc/push_swap.h"

static void	swap(t_stack *stack)
{
	int	head;

	if (stack == NULL || stack->next == NULL)
		return ;
	head = stack->value;
	stack->value = stack->next->value;
	stack->next->value = head;
}

void	swap_sa(t_stack **stack_a, int type)
{
	swap(*stack_a);
	if (type)
		swap_type("sa");
}

void	swap_sb(t_stack **stack_b, int type)
{
	swap(*stack_b);
	if (type)
		swap_type("sb");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b, int type)
{
	swap(*stack_a);
	swap(*stack_b);
	if (type)
		swap_type("ss");
}
