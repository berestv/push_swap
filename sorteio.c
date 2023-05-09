/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorteio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:47:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/09 13:29:07 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *a, t_stack *b)
{
	if (a->top->num > a->top->previous->num)
		ops(a, b, "sa");
}

void	sort3(t_stack *a, t_stack *b)
{
	int	t;

	t = a->top->num;
	if (t > a->top->next->num && a->top->next->num < a->top->previous->num)
		ops(a, b, "sa");
	if (t > a->top->next->num && a->top->next->num > a->top->previous->num)
	{
		ops(a, b, "sa");
		ops(a, b, "rra");
	}
	if (t > a->top->next->num)
}

void	sort5(t_stack *a, t_stack *b);