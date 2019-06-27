/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   general_sorting.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:17:34 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 16:43:41 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	back_to_a(t_stack *stack)
{
	int		rotation_nbr;
	char	*rotation;

	rotation_nbr = 0;
	rotation = ft_strnew(3);
	while (stack->b_size)
	{
		rotation_nbr = placing_in_a(stack->stack_a,
			stack->a_size, stack->stack_b[0], &rotation);
		while (rotation_nbr > 0)
		{
			if (ft_strequ(rotation, "ra"))
				apply_ra(stack);
			else
				apply_rra(stack);
			rotation_nbr--;
		}
		apply_pa(stack);
	}
	first_on_stack_a(stack);
	free(rotation);
}

static void	back_to_b(t_stack *stack)
{
	int index;

	index = 0;
	while (stack->a_size > 2)
	{
		index = define_min_elem(stack->stack_a, stack->a_size);
		if (index == 0)
			apply_pb(stack);
		else if (index <= stack->a_size / 2)
			apply_ra(stack);
		else if (index > stack->a_size / 2)
			apply_rra(stack);
	}
}

static void	define_moves(t_moves *best_move, t_stack *stack)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->a_rotation, "ra"))
			apply_ra(stack);
		else
			apply_rra(stack);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->b_rotation, "rb"))
			apply_rb(stack);
		else
			apply_rrb(stack);
		best_move->b_moves--;
	}
}

static void	apply_best_move(t_moves **best_move, t_stack **stack)
{
	if (ft_strequ((*best_move)->ab_rotation, "rr"))
		apply_rr(*stack);
	else
		apply_rrr(*stack);
	(*best_move)->ab_moves--;
}

void		general_sorting(t_stack *stack)
{
	t_moves *best_move;
	int		refiner;

	if (stack->a_size > 200)
		refiner = 50;
	else
		refiner = 2;
	while (stack->b_size != 2)
		apply_pb(stack);
	while (stack->a_size > refiner)
	{
		best_move = best_move_a_to_b(stack);
		while (best_move->ab_moves)
			apply_best_move(&best_move, &stack);
		define_moves(best_move, stack);
		apply_pb(stack);
		free_moves(best_move);
	}
	back_to_b(stack);
	back_to_a(stack);
}
