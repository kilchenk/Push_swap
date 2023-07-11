/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:55:26 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/13 20:11:19 by kilchenk         ###   ########.fr       */
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

//exit???
void	dead(char const *str)
{
	ft_putendl_fd((char *)str, 2);
	exit(1);
}

void	putendl_fd(char const *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen((char *)s));
	write(fd, "\n", 1);
}

int	sign(char c)
{
	return (c == '-' || c == '+');
}

int	get_min(t_stack **s)
{
	int		i;
	t_stack	*buf;

	buf = *s;
	if (s == NULL)
		return (0);
	i = buf->value;
	while (buf->next != NULL)
	{
		if (i > buf->next->value)
			i = buf->next->value;
		buf = buf->next;
	}
	return (i);
}

// void	output(t_stack *s)
// {
// 	while (s != NULL)
// 	{
// 		printf("%d\n", s->value);
// 		s = s->next;
// 	}
// }
