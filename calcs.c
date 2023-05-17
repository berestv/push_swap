/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:01:46 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/17 15:17:37 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort2(stack_a, stack_b);
	else if (stack_a->size == 3)
		sort3(stack_a, stack_b);
	else if (stack_a->size >= 4)
		sort5(stack_a, stack_b);
/*	else if (stack_a->size > 5)
		sort(stack_a, stack_b);*/
}
