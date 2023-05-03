/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:50:10 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/03 16:22:59 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*createnode(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->num = num;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	delfnode(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	stack->top = stack->top->next;
	stack->top->previous->previous->next = stack->top;
	stack->top->previous = stack->top->previous->previous;
	free(temp);
}

void	stack_change(t_node *new_node, t_stack *stack)
{
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->top->next = stack->top;
		stack->top->previous = stack->top;
		stack->size++;
		return ;
	}
	new_node->next = stack->top;
	new_node->previous = stack->top->previous;
	stack->top->previous->next = new_node;
	stack->top->previous = new_node;
	stack->top = new_node;
	stack->size++;
}
