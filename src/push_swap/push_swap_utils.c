/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:40:31 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/23 19:53:32 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
//exit???
void	dead(char const *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	swap_type(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int	sign(char c)
{
	return (c == '-' || c == '+');
}

long int	ft_atois(const char *str)
{
	int	mark;
	int	num;
	int	i;

	i = 0;
	num = 0;
	mark = 1;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			mark = -mark;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '8' && num == 214748364)
			return (-2147483648);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * mark);
}

void	free_split(char **number)
{
	size_t	i;

	i = 0;
	while (number[i])
	{
		free(number[i]);
		i++;
	}
	free(number);
}
