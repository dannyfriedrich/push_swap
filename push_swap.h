/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 15:57:54 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 16:49:34 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

# define PURPLE "\033[0;35m"
# define GREEN "\033[0;92m"
# define CYAN "\033[0;96m"
# define RESET "\033[0m"

typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			a_size;
	int			b_size;
	int			result;
	int			colour;
	int			print_stack;
	int			result_op;
	int			print_op;
}				t_stack;

typedef struct	s_moves
{
	int			elem;
	int			a_moves;
	int			b_moves;
	int			ab_moves;
	char		*a_rotation;
	char		*b_rotation;
	char		*ab_rotation;
	int			result;
}				t_moves;

void			init_stacks(t_stack *stack, int argc);
int				parsing_options(int *argc, char ***argv, t_stack *stack);
t_stack			*parsing_args(int argc, char **argv, t_stack *stack);
void			sorting(t_stack *stack);
void			apply_sa(t_stack *stack);
void			apply_sb(t_stack *stack);
void			apply_ss(t_stack *stack);
void			apply_pa(t_stack *stack);
void			apply_pb(t_stack *stack);
void			apply_ra(t_stack *stack);
void			apply_rb(t_stack *stack);
void			apply_rr(t_stack *stack);
void			apply_rra(t_stack *stack);
void			apply_rrb(t_stack *stack);
void			apply_rrr(t_stack *stack);
int				define_min_index(int *stack, int len);
int				define_max_index(int *stack, int len);
int				define_min_elem(int *stack, int stack_len);
int				define_max_elem(int *stack, int stack_len);
void			first_on_stack_a(t_stack *stack);
int				is_sorted(int *stack, int len);
int				is_reverse_sorted(int *stack, int len);
void			free_stack(t_stack *stack);
void			free_moves(t_moves *moves);
void			print_stacks(t_stack *stack);
int				define_rotation_a(int len, int pos, char **a_rotation);
int				define_rotation_b(int len, int pos, char **b_rotation);
t_moves			*best_move_a_to_b(t_stack *stack);
int				placing_in_a(int *stack, int len, int elem, char **rotation);
void			general_sorting(t_stack *stack);

#endif
