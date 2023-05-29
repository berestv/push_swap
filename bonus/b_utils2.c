/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:10:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/29 15:40:17 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	size2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	exec_ops(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (ops(a, b, str) != 1)
		{
			free(str);
			sender('e');
			return (-1);
		}
		free(str);
	}
	free(str);
	return (0);
}

int	sender(char type)
{
	if (type == 's')
	{
		write(1, "OK\n", 3);
		return (0);
	}
	if (type == 'e')
	{
		write(1, "Error\n", 6);
		return (-2);
	}
	if (type == 'f')
	{
		write(1, "KO\n", 3);
		return (-1);
	}
	return (0);
}

t_stack	*stk_cpy(t_stack *src)
{
	t_stack	*copied;

	if (src->size < 0)
		return (0);
	copied = malloc(sizeof(t_stack));
	copied->top = src->top;
	copied->size = src->size;
	copied->id = src->id;
	return (copied);
}

void	free_list(t_stack *a)
{
	while (a->size > 0)
		deathnode(a);
	free(a);
}
