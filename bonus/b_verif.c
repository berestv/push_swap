/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_verif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:43:43 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/30 12:29:30 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	dups(char **str, int size)
{
	int	i;

	while (size >= 0 && str[size])
	{
		i = size - 1;
		while (i > 0)
		{
			if (ft_atoi(str[size]) == ft_atoi(str[i]))
				return (-1);
			i--;
		}
		size--;
	}
	return (0);
}

int	isnum(char *str)
{
	if (ft_atoi(str) == 0)
		return (-1);
	if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (0);
	if (str[0] == '0' && ft_atoi(str) == 0 && (str[1] == ' ' || str[1] == '\0'))
		return (0);
	return (-1);
}

int	check_order_list(t_stack *stack)
{
	int		counter;
	t_stack	*copied;

	counter = 0;
	copied = stk_cpy(stack);
	while (copied->size >= 0)
	{
		if (copied->top->num < copied->top->next->num)
			counter++;
		copied->top = copied->top->next;
		copied->size--;
	}
	free_list(copied);
	if (counter == stack->size)
		return (-1);
	return (0);
}
