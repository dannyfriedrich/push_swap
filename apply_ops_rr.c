/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_ops_rr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 15:00:40 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 18:23:07 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rra(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->a_size == 0)
		return ;
	i = stack->a_size - 1;
	tmp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	if (stack->print_op)
		ft_printf("rra\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}

void	apply_rrb(t_stack *stack)
{
	int i;
	int tmp;

	if (stack->b_size == 0)
		return ;
	i = stack->b_size - 1;
	tmp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	if (stack->print_op)
		ft_printf("rrb\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}

void	apply_rrr(t_stack *stack)
{
	int tmp_ops;
	int tmp_stack;

	tmp_stack = stack->print_stack;
	tmp_ops = stack->print_op;
	stack->print_op = 0;
	stack->print_stack = 0;
	apply_rra(stack);
	apply_rrb(stack);
	stack->print_op = tmp_ops;
	stack->print_stack = tmp_stack;
	if (stack->print_op)
		ft_printf("rrr\n");
	if (stack->print_stack)
		print_stacks(stack);
	stack->result_op++;
}
