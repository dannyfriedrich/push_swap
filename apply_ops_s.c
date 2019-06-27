/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_ops_s.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 14:03:53 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 18:24:03 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_sa(t_stack *stack)
{
	int tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = tmp;
	if (stack->print_op)
		ft_printf("sa\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}

void	apply_sb(t_stack *stack)
{
	int tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = tmp;
	if (stack->print_op)
		ft_printf("sb\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}

void	apply_ss(t_stack *stack)
{
	int tmp_ops;
	int tmp_stack;

	tmp_stack = stack->print_stack;
	tmp_ops = stack->print_op;
	stack->print_op = 0;
	stack->print_stack = 0;
	apply_sa(stack);
	apply_sb(stack);
	stack->print_op = tmp_ops;
	stack->print_stack = tmp_stack;
	if (stack->print_op)
		ft_printf("ss\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}
