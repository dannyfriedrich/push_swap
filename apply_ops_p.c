/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_ops_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 14:05:09 by dfreire        #+#    #+#                */
/*   Updated: 2019/06/03 14:55:24 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		apply_pa(t_stack *stack)
{
	int i;

	if (stack->b_size == 0)
		return ;
	i = stack->a_size;
	while (i >= 0)
	{
		stack->stack_a[i + 1] = stack->stack_a[i];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i <= stack->b_size)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->a_size++;
	stack->b_size--;
	if (stack->print_op)
		ft_printf("pa\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}

void		apply_pb(t_stack *stack)
{
	int i;

	if (stack->a_size == 0)
		return ;
	i = stack->b_size;
	while (i >= 0)
	{
		stack->stack_b[i + 1] = stack->stack_b[i];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i <= stack->a_size - 1)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->b_size++;
	stack->a_size--;
	if (stack->print_op)
		ft_printf("pb\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}
