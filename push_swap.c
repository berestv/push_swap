/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/04/20 18:38:48 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_convert(t_stack *stack, char *str)
{
	int		i;
	int		size;
	char	**nospc;

	nospc = ft_split(str, ' ');
	i = ft_strlen(nospc) - 1;
	size = i;
	while (nospc[i])
		i++;
	while (i > 0)
	{
		stack_change(create_node(ft_atoi(nospc[i])), stack);
		i--;
	}
	while (size >= 0)
	{
		free(nospc[size]);
		size--;
	}
	free(nospc);
}

void	arg_convert(int argc, char **argv, t_stack *stack)
{
	argc--;
	while (argc > 0)
	{
		stack_change(create_node(ft_atoi(argv[argc])), stack);
		argc--;
	}
}

void	initialize(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc >= 2)
	{
		initialize(&stack_a, &stack_b);
		if (argc == 2)
			str_convert(&stack_a, argv[1]);
		if (argc >= 2)
			arg_convert(argc, argv, &stack_a);
		calculate(&stack_a, &stack_b);
		print_list(&stack_a);
		ft_printf("\n");
		print_list(&stack_b);
		free_list(&stack_a);
		free_list(&stack_b);
	}
	return (0);
}
