/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilchenk <kilchenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:19:16 by kilchenk          #+#    #+#             */
/*   Updated: 2024/01/22 12:35:43 by kilchenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/get_next_line.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct s_transf_price
{
	int	moves[2];
	int	value;
}				t_transf_price;

t_stack		*pars_str(char *str);
t_stack		*new_stack(int nb);
t_stack		*get_bot(t_stack *stack);
t_stack		*pars_arr(int argc, char **argv);
t_stack		*get_penult(t_stack *stack);
int			find_place(t_stack *a, int value);
int			main(int argc, char **argv);
int			arg_check(char *av);
int			sign(char c);
int			get_min(t_stack **s);
int			min_rotations(t_stack *a, int value);
int			input_check(char **av);
int			check_sorted(t_stack **stack);
int			check_max_value(t_stack **s);
int			check_min_value(t_stack **s);
int			check_rotate(t_transf_price *price, t_stack *a, t_stack *b);
void		dead(char const *str);
void		double_rot(t_transf_price *price, t_stack **a, \
			t_stack **b, int index);
void		single_rot(t_transf_price *price, t_stack **a, \
			t_stack **b, int index);
void		push_swap(t_stack **a, t_stack **b);
void		push_mid_b(t_stack **a, t_stack **b);
void		add_bot(t_stack **stack, t_stack *new);
void		free_split(char **number);
void		push_back_sort(t_stack **a, t_stack **b);
void		swap_type(char const *s);
void		three_sort(t_stack **s);
void		small_sort(t_stack **a, t_stack **b);
void		push_pa(t_stack **stack_a, t_stack **stack_b, int type);
void		push_pb(t_stack **stack_a, t_stack **stack_b, int type);
void		swap_sa(t_stack **stack_a, int type);
void		swap_sb(t_stack **stack_b, int type);
void		swap_ss(t_stack **stack_a, t_stack **stack_b, int type);
void		rotate_rr(t_stack **stack_a, t_stack **stack_b, int type);
void		rotate_rb(t_stack **stack_a, int type);
void		rotate_ra(t_stack **stack_a, int type);
void		rev_rot_rrr(t_stack **stack_a, t_stack **stack_b, int type);
void		rev_rot_rrb(t_stack **stack_b, int type);
void		rev_rot_rra(t_stack **stack_a, int type);
void		sort_type_check(t_stack **stack_a, t_stack **stack_b);
void		list_clear(t_stack **a);
long int	ft_atois(const char *str);
size_t		get_size(t_stack **stack);

#endif