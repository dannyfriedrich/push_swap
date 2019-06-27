/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handling_stacks.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 14:31:10 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/30 14:37:28 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int		is_reverse_sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	stack = NULL;
}

void	free_moves(t_moves *moves)
{
	free(moves->a_rotation);
	free(moves->b_rotation);
	free(moves->ab_rotation);
	free(moves);
	moves = NULL;
}

void	print_stacks(t_stack *stack)
{
	ft_printf("A: ");
	ft_int_to_array(stack->stack_a, stack->a_size);
	if (stack->b_size)
	{
		ft_printf("B: ");
		ft_int_to_array(stack->stack_b, stack->b_size);
	}
}
