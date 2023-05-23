/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:06:17 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/23 15:18:10 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stk_cpy(t_stack *src)
{
	t_stack	*copied;

	if (src->size < 0)
		return (0);
	copied = malloc(sizeof(t_stack));
	copied->top = src->top;
	copied->size = src->size;
	copied->id = src->id;
	return (copied);
}

void	movecount(t_nop *moves, t_stack *stack, int num)
{
	int	index;
	int	half;

	index = finddex(stack, num);
	half = stack->size / 2;
	if (index <= half)
	{
		if (stack->id == 'a')
			moves->ra = index;
		else
			moves->rb = index;
	}
	else if (index > half)
	{
		if (stack->id == 'a')
			moves->rra = (stack->size - index);
		else
			moves->rrb = (stack->size - index);
	}
}

int	finddex(t_stack *stack, int num)
{
	int		index;
	t_stack	*copied;

	index = 0;
	copied = stk_cpy(stack);
	while (copied->top->num != num)
	{
		copied->top = copied->top->next;
		index++;
	}
	free(copied);
	return (index);
}

int	lowernum(t_stack *stack, int num)
{
	t_stack	*copied;
	int		min;
	int		max;

	copied = stk_cpy(stack);
	min = find_limits_n(copied, '-');
	max = find_limits_n(copied, '+');
	if (num > max || num < min)
	{
		free(copied);
		return (max);
	}
	while (copied->size--)
	{
		if (num > copied->top->num && copied->top->num > min)
			min = copied->top->num;
		copied->top = copied->top->next;
	}
	free(copied);
	return (min);
}
