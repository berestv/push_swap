/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:52:45 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/24 11:16:26 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	free2d(char **arr, int size, char type)
{
	while (size >= 0)
	{
		free(arr[size]);
		size--;
	}
	free(arr);
	if (type == 'f')
		return (-1);
	return (0);
}

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
