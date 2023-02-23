/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:55:26 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/23 19:59:05 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_sorted(t_stack **stack)
{
	t_stack	*new;

	new = *stack;
	while (new->next != NULL)
	{
		if (new->value > new->next->value)
			return (0);
		new = new->next;
	}
	return (1);
}
