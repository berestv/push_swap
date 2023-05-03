/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:20:21 by marvin            #+#    #+#             */
/*   Updated: 2022/11/07 22:20:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sgn;

	i = 0;
	res = 0;
	sgn = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sgn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sgn);
}
/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int val;
	char str[20];

	strcpy(str, "-12345");
	val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);

	strcpy(str, "-12345");
	val = atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);

	return (0);
} */
