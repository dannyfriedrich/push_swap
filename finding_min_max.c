/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finding_min_max.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 13:57:09 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/30 12:57:35 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		define_min_index(int *stack, int len)
{
	int i;
	int tmp;
	int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		define_max_index(int *stack, int len)
{
	int i;
	int tmp;
	int index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		define_min_elem(int *stack, int stack_len)
{
	int i;
	int tmp;
	int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		define_max_elem(int *stack, int stack_len)
{
	int i;
	int tmp;
	int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	first_on_stack_a(t_stack *stack)
{
	int min_index;

	min_index = define_min_index(stack->stack_a, stack->a_size);
	if (min_index <= stack->a_size / 2)
		while (min_index)
		{
			apply_ra(stack);
			min_index--;
		}
	else
		while ((stack->a_size - min_index) > 0)
		{
			apply_rra(stack);
			min_index++;
		}
}
