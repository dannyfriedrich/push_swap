/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_ops_r.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 14:06:52 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 18:21:36 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_ra(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->a_size == 0)
		return ;
	i = 1;
	tmp = stack->stack_a[0];
	while (i < stack->a_size)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i - 1] = tmp;
	if (stack->print_op)
		ft_printf("ra\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}

void	apply_rb(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->b_size == 0)
		return ;
	i = 1;
	tmp = stack->stack_b[0];
	while (i < stack->b_size)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i - 1] = tmp;
	if (stack->print_op)
		ft_printf("rb\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}

void	apply_rr(t_stack *stack)
{
	int tmp_ops;
	int tmp_stack;

	tmp_ops = stack->print_op;
	tmp_stack = stack->print_stack;
	stack->print_op = 0;
	stack->print_stack = 0;
	apply_ra(stack);
	apply_rb(stack);
	stack->print_op = tmp_ops;
	stack->print_stack = tmp_stack;
	if (stack->print_op)
		ft_printf("rr\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}
