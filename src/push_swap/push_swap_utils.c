/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:40:31 by kilchenk          #+#    #+#             */
/*   Updated: 2024/04/22 14:47:32 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"


void	swap_type(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

long int	ft_atois(const char *str)
{
	long int	mark;
	long int	num;
	int			i;

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

int	check_max_value(t_stack **s)
{
	int		i;
	t_stack	*head;

	head = *s;
	if (s == NULL)
		return (0);
	i = head->value;
	while (head->next != NULL)
	{
		if (i < head->next->value)
			i = head->next->value;
		head = head->next;
	}
	return (i);
}

int	check_min_value(t_stack **s)
{
	int		i;
	t_stack	*head;

	head = *s;
	if (s == NULL)
		return (0);
	i = head->value;
	while (head->next != NULL)
	{
		if (i > head->next->value)
			i = head->next->value;
		head = head->next;
	}
	return (i);
}
