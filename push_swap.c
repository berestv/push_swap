/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/03 16:27:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	str_convert(t_stack *stack, char *str)
{
	int		i;
	int		size;
	char	**nospc;

	i = 0;
	nospc = ft_split(str, ' ');
	while (nospc[i])
		i++;
	size = i;
	i--;
	while (i > 0)
	{
		stack_change(createnode(ft_atoi(nospc[i])), stack);
		i--;
	}
	free2d(nospc, size);
}

void	arg_convert(int argc, char **argv, t_stack *stack)
{
	argc--;
	while (argc > 0)
	{
		stack_change(createnode(ft_atoi(argv[argc])), stack);
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

		printlist(&stack_a);
		/*calculate(&stack_a, &stack_b);
		print_list(&stack_a);
		ft_printf("\n");
		print_list(&stack_b);
		free_list(&stack_a);
		free_list(&stack_b);*/
	}
	return (0);
}
