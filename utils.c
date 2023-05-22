/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:29:10 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/22 14:46:53 by bbento-e         ###   ########.fr       */
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

/*void	printlist(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%i\n", stack->top->num);
		stack->top = stack->top->next;
		i++;
	}
}*/

int	find_limits(t_stack *stack, char op)
{
	int	pos;
	int	lim;
	int	i;

	i = 1;
	pos = i;
	lim = stack->top->num;
	while (stack->size >= i)
	{
		if (stack->top->num > lim && op == '+')
		{
			lim = stack->top->num;
			pos = i;
		}
		if (stack->top->num < lim && op == '-')
		{
			lim = stack->top->num;
			pos = i;
		}
		stack->top = stack->top->next;
		i++;
	}
	return (pos);
}

int	find_limits_N(t_stack *stack, char op)
{
	int	lim;
	int	i;

	i = 1;
	lim = stack->top->num;
	while (stack->size >= i)
	{
		if (stack->top->num > lim && op == '+')
			lim = stack->top->num;
		if (stack->top->num < lim && op == '-')
			lim = stack->top->num;
		stack->top = stack->top->next;
		i++;
	}
	return (lim);
}

void	sort5_xtra(t_stack *a, t_stack *b, int pos)
{
	if (pos > 1 && pos <= 3)
	{
		while (pos > 1)
		{
			ops(a, b, "ra");
			pos--;
		}
	}
	else if (pos > 3 && pos <= 5)
	{
		while (pos <= a->size)
		{
			ops(a, b, "rra");
			pos++;
		}
	}
}

void	b2bzero(t_nop *numops)
{
	numops->ra = 0;
	numops->rb = 0;
	numops->rr = 0;
	numops->rra = 0;
	numops->rrb = 0;
	numops->rrr = 0;
	numops->add = 0;
}