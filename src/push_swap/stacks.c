/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:13:18 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/22 13:52:35 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*new_stack(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		dead("Error");
	new->value = nb;
	new->next = NULL;
	return (new);
}

void	add_bot(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		dead("Error");
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_bot(*stack);
	tail->next = new;
}

t_stack	*get_bot(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
