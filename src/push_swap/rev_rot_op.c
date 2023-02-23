/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:23:41 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/23 19:24:27 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*penult;
	t_stack	*bot;

	penult = get_penult(*stack);
	bot = get_bot(*stack);
	head = *stack;
	*stack = bot;
	(*stack)->next = head;
	penult->next = NULL;
}

void	rev_rot_rra(t_stack **stack_a, int type)
{
	rev_rotate(*stack_a);
	if (type)
		swap_type("rra");
}

void	rev_rot_rrb(t_stack **stack_b, int type)
{
	rev_rotate(*stack_b);
	if (type)
		swap_type("rrb");
}

void	rev_rot_rrr(t_stack **stack_a, t_stack **stack_b, int type)
{
	rev_rotate(*stack_a);
	rev_rotate(*stack_b);
	if (type)
		swap_type("rrr");
}
