/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:12:12 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/22 15:57:04 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimizer(t_nop *numops)
{
	while (numops->ra > 0 && numops->rb > 0)
	{
		numops->ra--;
		numops->rb--;
		numops->rr++;
	}
	while (numops->rra > 0 && numops->rrb > 0)
	{
		numops->rra--;
		numops->rrb--;
		numops->rrr++;
	}
}

int	ops_sum(t_nop *numops)
{
	int	sum;

	optimizer(numops);
	sum = numops->ra;
	sum += numops->rb;
	sum += numops->rr;
	sum += numops->rra;
	sum += numops->rrb;
	sum += numops->rrr;
	numops->add = sum;
	return (sum);
}
