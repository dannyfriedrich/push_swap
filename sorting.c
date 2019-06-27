/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 09:46:35 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 18:28:31 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack *stack)
{
	int max_index;

	if (stack->a_size == 1)
		return ;
	if (stack->a_size == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			apply_sa(stack);
		return ;
	}
	else if (stack->a_size == 3)
	{
		max_index = define_max_elem(stack->stack_a, stack->a_size);
		if (max_index == 0)
			apply_ra(stack);
		if (max_index == 1)
			apply_rra(stack);
		if (stack->stack_a[0] > stack->stack_a[1])
			apply_sa(stack);
	}
}

static void	print_pre_sorted(t_stack *stack)
{
	if (stack->colour)
		ft_putstr(CYAN);
	ft_printf("Pre-sorted array: ");
	ft_int_to_array(stack->stack_a, stack->a_size);
	if (stack->colour)
		ft_putstr(PURPLE);
}

static void	print_sorted(t_stack *stack)
{
	if (stack->colour)
		ft_putstr(GREEN);
	ft_printf("Sorted array: ");
	ft_int_to_array(stack->stack_a, stack->a_size);
}

void		sorting(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->a_size) && stack->b_size == 0)
		return ;
	if (stack->print_stack)
		print_pre_sorted(stack);
	if (stack->a_size <= 3)
		return (sort(stack));
	else
		general_sorting(stack);
	if (stack->print_stack)
		print_sorted(stack);
	if (stack->result)
	{
		if (stack->colour)
			ft_putstr(CYAN);
		ft_printf("Total of %d operations\n", stack->result_op);
		if (stack->colour)
			ft_putstr(RESET);
	}
}
