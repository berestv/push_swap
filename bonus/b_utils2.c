/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:10:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/24 11:24:31 by bbento-e         ###   ########.fr       */
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

int	sender(char type)
{
	if (type == 's')
	{
		write(1, "OK", 2);
		return (0);
	}
	if (type == 'f')
	{
		write(1, "Error", 5);
		return (-1);
	}
	return (0);
}
