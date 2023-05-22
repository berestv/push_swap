/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:01:46 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/22 16:43:25 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort2(stack_a, stack_b);
	else if (stack_a->size == 3)
		sort3(stack_a, stack_b);
	else if (stack_a->size <= 5)
		sort5(stack_a, stack_b);
	else if (stack_a->size > 5)
		sort(stack_a, stack_b);
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
