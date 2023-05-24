/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:55:36 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/24 11:56:17 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		stack->top = stack->top->prev;
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
