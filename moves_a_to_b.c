/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves_a_to_b.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:55:57 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/30 13:30:03 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		placing_in_b(int *stack, int len, int elem, char **rotation)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	if (len == 2 && elem > stack[0] && elem < stack[len - 1])
		pos = 0;
	else if (len == 2 && elem < stack[0] && elem > stack[len - 1])
		pos = 1;
	else if (elem > stack[define_max_elem(stack, len)] ||
	elem < stack[define_min_elem(stack, len)])
		pos = define_max_elem(stack, len);
	else
		while (i < len)
		{
			if (elem < stack[i] && ((i + 1 < len && elem > stack[i + 1]) ||
			(i + 1 == len && elem > stack[0])))
			{
				pos = i + 1;
				break ;
			}
			i++;
		}
	return (define_rotation_b(len, pos, rotation));
}

static int		define_ab_moves(t_moves *moves)
{
	int		common_moves;

	common_moves = 0;
	if ((ft_strequ(moves->a_rotation, "rra") &&
		(ft_strequ(moves->b_rotation, "rrb"))) ||
		(ft_strequ(moves->a_rotation, "ra") &&
		(ft_strequ(moves->b_rotation, "rb"))))
	{
		if (moves->a_moves > moves->b_moves)
			common_moves = moves->b_moves;
		else
			common_moves = moves->a_moves;
		if (common_moves)
		{
			moves->ab_rotation = ft_strcpy(moves->ab_rotation,
			moves->a_rotation);
			moves->ab_rotation[ft_strlen(moves->ab_rotation) - 1] = 'r';
			moves->b_moves -= common_moves;
			moves->a_moves -= common_moves;
		}
	}
	return (common_moves);
}

static t_moves	*calc_moves_a_to_b(t_stack *stack, int pos)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->a_rotation = ft_strnew(3);
	moves->b_rotation = ft_strnew(3);
	moves->ab_rotation = ft_strnew(3);
	moves->elem = stack->stack_a[pos];
	moves->a_moves = define_rotation_a(stack->a_size, pos,
	&(moves->a_rotation));
	moves->b_moves = placing_in_b(stack->stack_b, stack->b_size,
	stack->stack_a[pos], &(moves->b_rotation));
	moves->ab_moves = define_ab_moves(moves);
	moves->result = moves->a_moves + moves->b_moves + moves->ab_moves + 1;
	return (moves);
}

t_moves			*best_move_a_to_b(t_stack *stack)
{
	int		i;
	t_moves	*best_move;
	t_moves	*moves;

	i = 0;
	while (i < stack->a_size)
	{
		moves = calc_moves_a_to_b(stack, i);
		if (i == 0)
			best_move = moves;
		else if (best_move->result > moves->result)
		{
			free_moves(best_move);
			best_move = moves;
		}
		else
			free_moves(moves);
		i++;
	}
	return (best_move);
}
