/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:10:12 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/04 12:15:44 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ops_picker(t_stack *stack_a, t_stack *stack_b, char *op_id)
{
	if (op_id == "sa")
		if (swap(stack_a) == 0)
			ft_printf("sa\n");
	else if (op_id == "sb")
		if (swap(stack_b) == 0)
			ft_printf("sb\n");
	else if (op_id == "ss")
		if (ss(stack_a, stack_b) == 0)
			ft_printf("ss\n");
	else if (op_id == "pa")
		if (push(stack_b, stack_a) == 0)
			ft_printf("pa\n");
	else if (op_id == "pb")
		if (push(stack_b, stack_a) == 0)
			ft_printf("pb\n");
	else if (op_id == "ra")
		if (rotate(stack_a) == 0)
			ft_printf("ra\n");
	else if (op_id == "rb")
		if (rotate(stack_a) == 0)
			ft_printf("rb\n");
	else
		ops2(stack_a, stack_b, op_id);
}

void	ops_picker2(t_stack *stack_a, t_stack *stack_b, char *op_id)
{

}

int	push(t_stack *src, t_stack *dest)
{
	stack_change(createnode(src->top->num), dest);
	deathnode(src);

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
