/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:55:27 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/24 12:03:41 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ops(t_stack *stack_a, t_stack *stack_b, char *op_id)
{
	if (ft_strncmp("sa", op_id, 2) == 0)
		return (swap(stack_a));
	if (ft_strncmp("sb", op_id, 2) == 0)
		return (swap(stack_b));
	if (ft_strncmp("ss", op_id, 2) == 0)
		return (ss(stack_a, stack_b));
	if (ft_strncmp("pa", op_id, 2) == 0)
		return (push(stack_b, stack_a));
	if (ft_strncmp("pb", op_id, 2) == 0)
		return (push(stack_a, stack_b));
	if (ft_strncmp("ra", op_id, 2) == 0)
		return (rotate(stack_a));
	if (ft_strncmp("rb", op_id, 2) == 0)
		return (rotate(stack_b));
	if (ft_strncmp("rra", op_id, 3) == 0)
		return (rev_rot(stack_a));
	if (ft_strncmp("rrb", op_id, 3) == 0)
		return (rev_rot(stack_b));
	if (ft_strncmp("rrr", op_id, 3) == 0)
		return (rrr(stack_a, stack_b));
	if (ft_strncmp("rr", op_id, 3) == 0)
		return (rotrot(stack_a, stack_b));
	return (-1);
}

int	push(t_stack *src, t_stack *dest)
{
	if (src->size == 0)
		return (-1);
	stack_change(createnode(src->top->num), dest);
	deathnode(src);
	return (1);
}

int	swap(t_stack *stack)
{
	int	temp;

	if (stack->size >= 2)
	{
		temp = stack->top->num;
		stack->top->num = stack->top->next->num;
		stack->top->next->num = temp;
		return (1);
	}
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (swap(stack_a) == 1 && swap(stack_b) == 1)
		return (1);
	return (0);
}
