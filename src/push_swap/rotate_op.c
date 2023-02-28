/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:09:59 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/28 14:35:40 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*bot;

	head = *stack;
	bot = get_bot(*stack);
	bot = *stack;
	*stack = (*stack)->next;
	head->next = NULL;
}

void	rotate_ra(t_stack **stack_a, int type)
{
	rotate(stack_a);
	if (type)
		swap_type("ra");
}

void	rotate_rb(t_stack **stack_a, int type)
{
	rotate(stack_a);
	if (type)
		swap_type("rb");
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b, int type)
{
	rotate(stack_a);
	rotate(stack_b);
	if (type)
		swap_type("rr");
}
