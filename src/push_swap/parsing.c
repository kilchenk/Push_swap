/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:52:25 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/14 19:23:02 by kilchenk         ###   ########.fr       */
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
		error("Error");
	
}
