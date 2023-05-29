/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:55:27 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/29 17:55:17 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ops(t_stack *stack_a, t_stack *stack_b, char *op_id)
{
	if (ft_strncmp("sa\n", op_id, 3) == 0)
		return (swap(stack_a));
	if (ft_strncmp("sb\n", op_id, 3) == 0)
		return (swap(stack_b));
	if (ft_strncmp("ss\n", op_id, 3) == 0)
		return (ss(stack_a, stack_b));
	if (ft_strncmp("pa\n", op_id, 3) == 0)
		return (push(stack_b, stack_a));
	if (ft_strncmp("pb\n", op_id, 3) == 0)
		return (push(stack_a, stack_b));
	if (ft_strncmp("ra\n", op_id, 3) == 0)
		return (rotate(stack_a));
	if (ft_strncmp("rb\n", op_id, 3) == 0)
		return (rotate(stack_b));
	if (ft_strncmp("rra\n", op_id, 4) == 0)
		return (rev_rot(stack_a));
	if (ft_strncmp("rrb\n", op_id, 4) == 0)
		return (rev_rot(stack_b));
	if (ft_strncmp("rrr\n", op_id, 4) == 0)
		return (rrr(stack_a, stack_b));
	if (ft_strncmp("rr\n", op_id, 3) == 0)
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
