/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/18 12:49:49 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_convert(char *str, t_stack *stack)
{
	int		i;
	int		size;
	char	**nospc;

	i = 0;
	nospc = ft_split(str, ' ');
	if (!nospc)
		return (-1);
	while (nospc[i])
		i++;
	size = i;
	i--;
	if (dups(nospc, size, 's') != -1 && isnum(str) != -1)
	{
		while (i > 0)
		{
			stack_change(createnode(ft_atoi(nospc[i])), stack);
			i--;
		}
		free2d(nospc, size);
		return (0);
	}
	free2d(nospc, size);
	return (-1);
}

int	arg_convert(int argc, char *argv[], t_stack *stack)
{
	argc--;
	if (dups(argv, argc, 'a') == -1)
		return (-1);
	while (argc > 0)
	{
		if (isnum(argv[argc]) == -1)
			return (-1);
		stack_change(createnode(ft_atoi(argv[argc])), stack);
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_a = malloc(sizeof (t_stack));
		stack_b = malloc(sizeof (t_stack));
		initialize(stack_a, stack_b);
		if (argc == 2)
			str_convert(argv[1], stack_a);
		if (argc > 2)
			arg_convert(argc, argv, stack_a);
		calculate(stack_a, stack_b);
		/*print_list(stack_a);
		ft_printf("\n");
		print_list(stack_b);
		free_list(stack_a);
		free_list(stack_b);*/
	}
	return (0);
}
