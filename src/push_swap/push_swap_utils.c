/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:40:31 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/14 17:58:42 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	error(char const *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	sign(char c)
{
	return (c == '-' || c == '+');
}
