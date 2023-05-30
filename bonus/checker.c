/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:40:04 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/30 12:21:16 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	arg_convert(int argc, char *argv[], t_stack *a)
{
	argc--;
	if (!argv[1])
		return (-1);
	if (dups(argv, argc) == -1)
		return (-2);
	while (argc > 0)
	{
		if (isnum(argv[argc]) == -1)
			return (-2);
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
	if (check_order_list(a) == -1)
		return (sender('s'));
	if (exec_ops(a, b) == -1)
		return (sender('e'));
	if (check_order_list(a) == -1)
		return (sender('s'));
	sender('f');
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 2)
		return (0);
	stack_a = malloc(sizeof (t_stack));
	stack_b = malloc(sizeof (t_stack));
	initialize(stack_a, stack_b);
	if (arg_convert(argc, argv, stack_a) == 0)
	{
		if (checker(stack_a, stack_b) == -1)
			return (free_lists(stack_a, stack_b));
	}
	else if (arg_convert(argc, argv, stack_a) == -2)
		sender('e');
	else
		sender('f');
	free_lists(stack_a, stack_b);
	return (0);
}
