/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:29:10 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/15 17:14:03 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free2d(char **arr, int size)
{
	while (size >= 0)
	{
		free(arr[size]);
		size--;
	}
	free(arr);
}

void	printlist(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%i\n", stack->top->num);
		stack->top = stack->top->next;
		i++;
	}
}

int	find_limits(t_stack *stack, char *op)
{
	int	pos;
	int	lim;
	int	i;

	i = 1;
	pos = i;
	lim = stack->top->num;
	while (stack->size >= i)
	{
		if (stack->top->num > lim && op == "max")
		{
			lim = stack->top->num;
			pos = i;
		}
		else if (stack->top->num < lim && op == "min")
		{
			lim = stack->top->num;
			pos = i;
		}
		stack->top = stack->top->next;
		i++;
	}
	return (pos);
}
