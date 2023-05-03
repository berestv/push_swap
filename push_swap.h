/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:24:16 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/02 18:30:30 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	struct s_node		*top;
	int					size;
}						t_stack;

typedef struct s_node
{
	int					num;
	struct s_node		*next;
	struct s_node		*previous;
}						t_node;
t_node	*create_node(int num);
void	stack_change(t_node *new_node, t_stack *stack);
void	initialize(t_stack *stack_a, t_stack *stack_b);
void	del_fnode(t_stack *stack);
void	free_list(t_stack *stack);

// ---------- OPERATIONS ---------- //
void	ops(t_stack *stack_a, t_stack *stack_b, char *op_id);
void	ops2(t_stack *stack_a, t_stack *stack_b, char *op_id);
int		swap(t_stack *stack_a);
int		rotate(t_stack *stack);
int		rr(t_stack *stack_a, t_stack *stack_b);
int		rev_rot(t_stack *stack);
int		rrr(t_stack *stack_a, t_stack *stack_b);
int		push(t_stack *src, t_stack *dest);
int		ss(t_stack *stack_a, t_stack *stack_b);

// ------------ SORT ------------ //
void	calculate(t_stack *stack_a, t_stack *stack_b);
void	sort2(t_stack *stack_a, t_stack *stack_b);
void	sort3(t_stack *stk, t_stack *stk_b);
void	sort5(t_stack *stack_a, t_stack *stack_b);
#endif
