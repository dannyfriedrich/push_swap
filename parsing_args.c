/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_args.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:04:18 by dfreire        #+#    #+#                */
/*   Updated: 2019/06/04 09:58:01 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validating_args(char **argv, char *arg, int start)
{
	int i;

	i = 0;
	while (*arg && arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN)
		return (0);
	while (argv[start] && argv && arg)
	{
		if (ft_strequ(argv[start], arg))
			return (0);
		start++;
	}
	return (1);
}

void		init_stacks(t_stack *stack, int argc)
{
	stack->stack_a = (int *)malloc(sizeof(int) * (argc + 1));
	stack->stack_b = (int *)ft_memalloc(sizeof(int) * (argc + 1));
	stack->a_size = argc;
	stack->b_size = 0;
	stack->result_op = 0;
	stack->print_op = 1;
}

int			parsing_options(int *argc, char ***argv, t_stack *stack)
{
	int i;

	i = 0;
	stack->result = 0;
	stack->colour = 0;
	stack->print_stack = 0;
	while (i < *argc && *((*argv)[i]) == '-' && !ft_isdigit((*argv)[i][1]))
	{
		if (ft_strequ((*argv)[i], "-v"))
			stack->print_stack = 1;
		else if (ft_strequ((*argv)[i], "-t"))
			stack->result = 1;
		else if (ft_strequ((*argv)[i], "-c"))
			stack->colour = 1;
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("usage: ./push_swap [-v -c -t] [numbers]\n", 2);
			exit(1);
		}
		i++;
	}
	*argc -= i;
	*argv += i;
	return (i);
}

t_stack		*parsing_args(int argc, char **argv, t_stack *stack)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (validating_args(argv, argv[i], i + 1))
			stack->stack_a[i] = ft_atoi(argv[i]);
		else
		{
			free_stack(stack);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (stack);
}
