/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:19:16 by kilchenk          #+#    #+#             */
/*   Updated: 2023/02/22 19:35:22 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

t_stack		*pars_str(char *str);
t_stack		*new_stack(int nb);
t_stack		*get_bot(t_stack *stack);
t_stack		*pars_arr(int argc, char **argv);
int			main(int argc, char **argv);
int			arg_check(char *av);
int			sign(char c);
int			input_check(char **av);
void		dead(char const *str);
void		add_bot(t_stack **stack, t_stack *new);
void		free_split(char **number);
void		swap_type(char const *s);
void		push_pa(t_stack **stack_a, t_stack **stack_b, int type);
void		push_pb(t_stack **stack_a, t_stack **stack_b, int type);
static int	arg_zero(char *av);
static int	duplicate(char *av);
long int	ft_atois(const char *str);
static void	push(t_stack **stack_a, t_stack **stack_b);

#endif