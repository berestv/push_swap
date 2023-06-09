/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/30 18:46:50 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_convert(t_stack *a, t_stack *b, char *str)
{
	int		i;
	int		size;
	char	**nospc;

	i = 0;
	nospc = ft_split(str, ' ');
	if (!nospc[0] || num_check(nospc) == -1)
		return (free2d(nospc, 0, 'a'));
	while (nospc[i])
		i++;
	size = i;
	i--;
	if (dups(nospc, size - 1, 's') != -1)
	{
		while (i >= 0)
		{
			if (isnum(nospc[i]) == -1)
				return (free2d(nospc, size, 'e'));
			stack_change(createnode(ft_atoi(nospc[i])), a);
			i--;
		}
		calculate(a, b);
	}
	free2d(nospc, size, 'a');
}

void	arg_convert(int argc, char *argv[], t_stack *a, t_stack *b)
{
	argc--;
	if (dups(argv, argc, 'a') == -1)
		return ;
	while (argc > 0)
	{
		if (isnum(argv[argc]) == -1)
			return (err_handler());
		stack_change(createnode(ft_atoi(argv[argc])), a);
		argc--;
	}
	calculate(a, b);
}

void	initialize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_a->id = 'a';
	stack_b->size = 0;
	stack_b->id = 'b';
}

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	stack_a = malloc(sizeof (t_stack));
	stack_b = malloc(sizeof (t_stack));
	initialize(stack_a, stack_b);
	if (argc == 2)
		str_convert(stack_a, stack_b, argv[1]);
	while (i < argc)
	{
		if (isnum(argv[i]) == -1)
			return (err_handler_int());
		i++;
	}
	if (argc > 2 && num_check(argv))
		arg_convert(argc, argv, stack_a, stack_b);
	free_lists(stack_a, stack_b);
	return (0);
}
