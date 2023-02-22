/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:00:37 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/22 19:34:56 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../inc/push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	if (*stack_b == NULL)
		return ;
	head = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = head;
}

void	push_pa(t_stack **stack_a, t_stack **stack_b, int type)
{
	push(stack_a, stack_b);
	if (type)
		swap_type("pa");
}

void	push_pb(t_stack **stack_a, t_stack **stack_b, int type)
{
	push(stack_b, stack_a);
	if (type)
		swap_type("pb");
}
