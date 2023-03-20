/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:00:46 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/20 20:51:46 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../inc/push_swap.h"

int	arg_check(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (ft_isdigit(av[i]) && av[i])
		i++;
	if (!ft_isdigit(av[i]) && av[i] != '\0')
		return (0);
	return (1);
}

static int	arg_zero(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

static int	duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && ft_atois(av[i]) == ft_atois(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
		zero += arg_zero(av[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (duplicate(av))
		return (0);
	return (1);
}

void	list_clear(t_stack **a)
{
	t_stack	*cur;
	t_stack	*next;

	cur = *a;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*a = NULL;
}
