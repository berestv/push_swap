/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:40:04 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/23 18:51:52 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	str_convert(t_stack *a, t_stack *b, char *str)
{
	int		i;
	int		size;
	char	**nospc;

	i = 0;
	nospc = ft_split(str, ' ');
	if (!nospc[0])
		return (free2d(nospc, 0));
	while (nospc[i])
		i++;
	size = i;
	i--;
	if (dups(nospc, size - 1, 's') != -1)
	{
		while (i >= 0)
		{
			if (isnum(nospc[i]) == -1)
				return (free2d(nospc, size));
			stack_change(createnode(ft_atoi(nospc[i])), a);
			i--;
		}
		calculate(a, b);
	}
	free2d(nospc, size);
}

void	arg_convert(int argc, char *argv[], t_stack *a, t_stack *b)
{
	argc--;
	if (dups(argv, argc, 'a') == -1)
		return ;
	while (argc > 0)
	{
		if (isnum(argv[argc]) == -1)
			return ;
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
	(void)argc;
	(void)argv;
	return (0);
}
