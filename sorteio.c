/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorteio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:47:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/15 18:58:24 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *a, t_stack *b)
{
	if (a->top->num > a->top->prev->num)
		ops(a, b, "sa");
}

void	sort3(t_stack *a, t_stack *b)
{
	if (a->top->num > a->top->next->num && a->top->num < a->top->prev->num
		&& a->top->next->num < a->top->prev->num)
		ops(a, b, "sa");
	if (a->top->num > a->top->next->num && a->top->num > a->top->prev->num
		&& a->top->next->num > a->top->prev->num)
	{
		ops(a, b, "sa");
		ops(a, b, "rra");
	}
	if (a->top->num > a->top->next->num && a->top->num > a->top->prev->num
		&& a->top->next->num < a->top->prev->num)
		ops(a, b, "ra");
	if (a->top->num < a->top->next->num && a->top->num < a->top->prev->num
		&& a->top->next->num > a->top->prev->num)
	{
		ops(a, b, "sa");
		ops(a, b, "ra");
	}
	if (a->top->num < a->top->next->num && a->top->num > a->top->prev->num
		&& a->top->next->num > a->top->prev->num)
		ops(a, b, "rra");
}

void	sort5(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_limits(a, "min");
	sort5_xtra(a, b, pos);
	ops(a, b, "pb");
	if (a->size == 4)
	{
		pos = find_limits(a, "max");
		sort5_xtra(a, b, pos);
		ops(a, b, "pb");
	}
	else if ()
	{
		
	}
}

void	sort5_xtra(t_stack *a, t_stack *b, int pos)
{
	if (pos > 1 && pos <= 3)
	{
		while (pos > 1)
		{
			ops(a, b, "ra");
			pos--;
		}
	}
	else if (pos > 3 && pos <= 5)
	{
		while (pos > 1)
		{
			ops(a, b, "rra");
			pos--;
		}
	}
}
