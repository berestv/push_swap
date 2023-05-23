/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:50:10 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/23 15:09:17 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*createnode(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	deathnode(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev->prev->next = stack->top;
	stack->top->prev = stack->top->prev->prev;
	stack->size--;
	free(temp);
}

void	stack_change(t_node *new_node, t_stack *stack)
{
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->top->next = stack->top;
		stack->top->prev = stack->top;
		stack->size++;
		return ;
	}
	new_node->next = stack->top;
	new_node->prev = stack->top->prev;
	stack->top->prev->next = new_node;
	stack->top->prev = new_node;
	stack->top = new_node;
	stack->size++;
}

void	free_lists(t_stack *a, t_stack *b)
{
	while (a->size > 0)
		deathnode(a);
	while (b->size > 0)
		deathnode(b);
	free(a);
	free(b);
}

void	free_list(t_stack *stack)
{
	while (stack->size > 0)
		deathnode(stack);
	free(stack);
}
