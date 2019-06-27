/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:23:48 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 16:20:12 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_ops(t_stack *stack, char *op)
{
	if (ft_strequ(op, "sa"))
		apply_sa(stack);
	else if (ft_strequ(op, "sb"))
		apply_sb(stack);
	else if (ft_strequ(op, "ss"))
		apply_ss(stack);
	else if (ft_strequ(op, "pa"))
		apply_pa(stack);
	else if (ft_strequ(op, "pb"))
		apply_pb(stack);
	else if (ft_strequ(op, "ra"))
		apply_ra(stack);
	else if (ft_strequ(op, "rb"))
		apply_rb(stack);
	else if (ft_strequ(op, "rr"))
		apply_rr(stack);
	else if (ft_strequ(op, "rra"))
		apply_rra(stack);
	else if (ft_strequ(op, "rrb"))
		apply_rrb(stack);
	else if (ft_strequ(op, "rrr"))
		apply_rrr(stack);
	else
		return (-1);
	return (0);
}

static void	execute_ops(t_stack *stack)
{
	char *op;

	while (get_next_line(0, &op) > 0)
	{
		if (!op)
			break ;
		if (get_ops(stack, op))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			free(op);
			exit(1);
		}
		free(op);
		op = NULL;
	}
	free(op);
}

static char	**split_args(int *argc, char ***argv)
{
	char **tmp;

	tmp = ft_strsplit((*argv)[0], ' ');
	*argc = 0;
	while (tmp && tmp[*argc])
		(*argc)++;
	if (argc == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (tmp);
}

int			main(int argc, char **argv)
{
	t_stack		*stack;
	int			options;

	if (argc == 1)
		exit(0);
	else
	{
		argv++;
		argc--;
	}
	stack = (t_stack *)malloc(sizeof(t_stack));
	options = parsing_options(&argc, &argv, stack);
	if (argc == 1)
		argv = split_args(&argc, &argv);
	init_stacks(stack, argc);
	stack = parsing_args(argc, argv, stack);
	stack->print_op = 0;
	if (!(is_sorted(stack->stack_a, stack->a_size)))
		execute_ops(stack);
	if (is_sorted(stack->stack_a, stack->a_size))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(stack);
	return (0);
}
