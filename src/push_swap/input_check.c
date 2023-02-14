/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:00:46 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/14 19:16:17 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	arg_check(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]) && av[i + 1] != '\0') /* ? */
		i++;
	while (ft_isdigit(av[i]) && av[i])
		i++;
	if (!ft_isdigit(av[i]) && av[i] != '0')
		return (0);
	return (1);
}

int	input_check(char **av)
{
	int	i;
	int	zero;

	zero = 0;
	i = 0;
	while (av[i])
	{
		if (!arg_check(av[i]))
			return (0);
		
	}
	
}
