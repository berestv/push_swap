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

void	execute(t_stack *a, t_stack *b, t_nop *numops)
{
	while (numops->ra)
	{
		ops(a, b, "ra");
		numops->ra--;
	}
	while (numops->rb)
	{
		ops(a, b, "rb");
		numops->rb--;
	}
	while (numops->rr)
	{
		ops(a, b, "rr");
		numops->rr--;
	}
	while (numops->rra)
	{
		ops(a, b, "rra");
		numops->rra--;
	}
	execute2(a, b, numops);
}

void	execute2(t_stack *a, t_stack *b, t_nop *numops)
{
	while (numops->rrb)
	{
		ops(a, b, "rrb");
		numops->rrb--;
	}
	while (numops->rrr)
	{
		ops(a, b, "rrr");
		numops->rrr--;
	}
	ops(a, b, "pb");
}
