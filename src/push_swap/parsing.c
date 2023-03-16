/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:52:25 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/14 13:22:57 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*pars_str(char *str)
{
	t_stack		*new;
	long int	nb;
	char		**number;
	int			i;

	number = ft_split(str, ' ');
	if (!input_check(number))
		dead("Error");
	i = 0;
	while (number[i])
	{
		nb = ft_atois(number[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			dead("Error");
		if (i == 0)
			new = new_stack((int)nb);
		else
			add_bot(&new, new_stack((int)nb));
		i++;
	}
	free_split(number);
	return (new);
}

t_stack	*pars_arr(int argc, char **argv)
{
	t_stack		*new;
	long int	nb;
	int			i;

	i = 1;
	if (!input_check(argv + 1))
		dead("Error");
	while (i < argc)
	{
		nb = ft_atois(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			dead("Error");
		if (i == 1)
			new = new_stack((int)nb);
		else
			add_bot(&new, new_stack((int)nb));
		i++;
	}
	return (new);
}
