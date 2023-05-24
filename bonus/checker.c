/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:40:04 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/24 12:31:52 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	str_convert(t_stack *a, char *str)
{
	int		i;
	int		size;
	char	**nospc;

	nospc = ft_split(str, ' ');
	if (!nospc[0])
		return (free2d(nospc, 0, 'f'));
	i = size2d(nospc) - 1;
	size = size2d(nospc);
	if (dups(nospc, size - 1, 's') != -1)
	{
		while (i >= 0)
		{
			if (isnum(nospc[i]) == -1)
				return (free2d(nospc, size, 'f'));
			stack_change(createnode(ft_atoi(nospc[i])), a);
			i--;
		}
	}
	else
		return (free2d(nospc, size, 'f'));
	free2d(nospc, size, 's');
	return (0);
}

int	arg_convert(int argc, char *argv[], t_stack *a)
{
	argc--;
	if (dups(argv, argc, 'a') == -1)
		return (-1);
	while (argc > 0)
	{
		if (isnum(argv[argc]) == -1)
			return (-1);
		stack_change(createnode(ft_atoi(argv[argc])), a);
		argc--;
	}
	return (0);
}

void	initialize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->id = 'a';
	stack_b->size = 0;
	stack_b->id = 'b';
}

int	checker(t_stack *a, t_stack *b)
{
	if (exec_ops(a, b) == -1)
	{
		sender('f');
		return (-1);
	}
	if (check_order_list(a) == 0)
		sender('s');
	else
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof (t_stack));
	stack_b = malloc(sizeof (t_stack));
	initialize(stack_a, stack_b);
	if (argc == 2 && str_convert(stack_a, argv[1]) != -1)
		checker(stack_a, stack_b);
	else if (argc > 2 && arg_convert(argc, argv, stack_a) != -1)
		checker(stack_a, stack_b);
	else
		sender('f');
	free_lists(stack_a, stack_b);
	return (0);
}
