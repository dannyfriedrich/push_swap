/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   define_rotations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 13:59:01 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/30 14:56:16 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		define_rotation_a(int len, int pos, char **a_rotation)
{
	if (pos > len / 2)
	{
		*a_rotation = ft_strcpy(*a_rotation, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rotation = ft_strcpy(*a_rotation, "ra");
	return (pos);
}

int		define_rotation_b(int len, int pos, char **b_rotation)
{
	if (pos > len / 2)
	{
		*b_rotation = ft_strcpy(*b_rotation, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rotation = ft_strcpy(*b_rotation, "rb");
	return (pos);
}

int		placing_in_a(int *stack, int len, int elem, char **rotation)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		pos = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		pos = 0;
	else if (elem > stack[define_max_elem(stack, len)] ||
			elem < stack[define_min_elem(stack, len)])
		pos = define_min_elem(stack, len);
	else
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) ||
			(i + 1 == len && elem < stack[0])))
			{
				pos = i + 1;
				break ;
			}
			i++;
		}
	return (define_rotation_a(len, pos, rotation));
}
