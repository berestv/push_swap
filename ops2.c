/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:06:10 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/09 11:37:33 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *stack)
{
	if (stack->size >= 2)
	{
		stack->top = stack->top->next;
		return (1);
	}
	return (0);
}

int	rotrot(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate(stack_a) == 1 && rotate(stack_b) == 1)
		return (1);
	return (0);
}

int	rev_rot(t_stack *stack)
{
	if (stack->size >= 2)
	{
		stack->top = stack->top->previous;
		return (1);
	}
	return (0);
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (rev_rot(stack_a) == 1 && rev_rot(stack_b) == 1)
		return (1);
	return (0);
}
