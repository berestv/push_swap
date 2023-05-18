/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorteio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:47:24 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/18 12:30:19 by bbento-e         ###   ########.fr       */
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

	pos = find_limits(a, '-');
	sort5_xtra(a, b, pos);
	ops(a, b, "pb");
	if (a->size == 4)
	{
		pos = find_limits(a, '+');
		sort5_xtra(a, b, pos);
		ops(a, b, "pb");
	}
	sort3(a, b);
	if (a->size == 3 && b->size == 2)
	{
		ops(a, b, "pa");
		ops(a, b, "ra");
		ops(a, b, "pa");
	}
	else if (a->size == 3 && b->size == 1)
		ops(a, b, "pa");
}

void	sort(t_stack *a, t_stack *b)
{
	t_nop	numops;

	b2bzero(&numops);
	ops(a, b, "pb");
	ops(a, b, "pb");
	while (a->size > 0)
	{
		numops = best(a, b);
	}
}

t_nop	best(t_stack *a, t_stack *b)
{
	t_nop	numops;
	t_nop	best;
	t_stack	*copied;

	copied = stk_cpy(a);
	b2bzero(&numops);

}
