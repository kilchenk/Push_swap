/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:38:49 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/27 19:36:52 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == 0))
		dead("Error");
	if (argc == 2 && !arg_check(argv[1]))
		a = pars_str(argv[1]);
	else
		a = pars_arr(argc, argv);
	sort_type_check(&a, &b);
	return (0);
}
