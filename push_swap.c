/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 16:54:17 by dfreire        #+#    #+#                */
/*   Updated: 2019/05/31 18:30:59 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*stack;
	int		options;

	if (argc == 1)
	{
		ft_putstr_fd("usage: ./push_swap [-v -c -t] [numbers]\n", 2);
		exit(0);
	}
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
	sorting(stack);
	free_stack(stack);
	return (0);
}
