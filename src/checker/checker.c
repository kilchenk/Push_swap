/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:33:30 by kilchenk          #+#    #+#             */
/*   Updated: 2023/03/20 20:51:40 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_result(t_stack *a, t_stack *b)
{
	if (check_sorted(&a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	read_op(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 4))
		swap_sa(a, 0);
	else if (!ft_strncmp(op, "sb\n", 4))
		swap_sb(b, 0);
	else if (!ft_strncmp(op, "ss\n", 4))
		swap_ss(a, b, 0);
	else if (!ft_strncmp(op, "ra\n", 4))
		rotate_ra(a, 0);
	else if (!ft_strncmp(op, "rb\n", 4))
		rotate_rb(b, 0);
	else if (!ft_strncmp(op, "rr\n", 4))
		rotate_rr(a, b, 0);
	else if (!ft_strncmp(op, "pa\n", 4))
		push_pa(a, b, 0);
	else if (!ft_strncmp(op, "pb\n", 4))
		push_pb(a, b, 0);
	else if (!ft_strncmp(op, "rra\n", 5))
		rev_rot_rra(a, 0);
	else if (!ft_strncmp(op, "rrb\n", 5))
		rev_rot_rrb(b, 0);
	else if (!ft_strncmp(op, "rrr\n", 5))
		rev_rot_rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static t_stack	*parse(int argc, char **argv)
{
	t_stack	*new;

	if (argc == 2 && !arg_check(argv[1]))
		new = pars_str(argv[1]);
	else
		new = pars_arr(argc, argv);
	return (new);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	a = parse(argc, argv);
	op = get_next_line(0);
	while (op)
	{
		if (!read_op(&a, &b, op))
		{
			free(op);
			list_clear(&a);
			dead("Error");
		}
		free(op);
		op = get_next_line(0);
	}
	free(op);
	print_result(a, b);
	list_clear(&a);
	list_clear(&b);
	return (0);
}
