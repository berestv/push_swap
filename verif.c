/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:27:08 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/17 15:57:27 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	verifall(char **str, int size, char *op)
{
	if (dups(str, size, op) == -1)
		return (-1);
	else if (protect())
		return (-1);
	return (0);
}*/

int	dups(char **str, int size, char op)
{
	int	i;

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
	if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	if (ft_atoi(str) == 0)
		return (-1);
	return (-1);
}