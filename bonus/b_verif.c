/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:52:28 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/24 12:26:02 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:27:08 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/23 17:13:22 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	dups(char **str, int size, char op)
{
	int	i;

	if (check_order(str, size) == -1)
		return (-1);
	while (size >= 0 && str[size])
	{
		i = size - 1;
		while (i >= 0 && op == 's' && str[i])
		{
			if (ft_atoi(str[size]) == ft_atoi(str[i]))
				return (-1);
			i--;
		}
		while (i > 0 && op == 'a')
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
	if (str[0] == '0' && ft_atoi(str) == 0 && (str[1] == ' ' || str[1] == '\0'))
		return (0);
	if (ft_atoi(str) == 0)
		return (-1);
	if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	return (-1);
}

int	check_order(char **str, int size)
{
	int	i;
	int	j;
	int	count;

	i = size - 1;
	j = size;
	count = 1;
	while (i >= 0 && str[i])
	{
		if (ft_atoi(str[i]) < ft_atoi(str[j]))
			count++;
		j--;
		i--;
	}
	if (count >= size)
		return (-1);
	return (0);
}

int	check_order_list(t_stack *stack)
{
	int		counter;
	t_stack	*copied;

	counter = 0;
	copied = stk_cpy(stack);
	while (copied->size > 0)
	{
		if (copied->top->num < copied->top->next->num)
			counter++;
		copied->top = copied->top->next;
		copied->size--;
	}
	if (counter == stack->size)
		return (0);
	return (-1);
}