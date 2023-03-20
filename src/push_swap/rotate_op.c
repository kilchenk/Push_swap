/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:09:59 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/20 20:51:50 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*bot;

	head = *stack;
	*stack = (*stack)->next;
	bot = get_bot(*stack);
	head->next = NULL;
	bot->next = head;
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
