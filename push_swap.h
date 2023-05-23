/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:24:16 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/23 17:46:38 by bbento-e         ###   ########.fr       */
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
	char				id;
}						t_stack;

typedef struct s_node
{
	int					num;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct n_op
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	add;
}		t_nop;


// ------------ CHECKS ------------ //
int		check_order(char **str, int size);
int		dups(char **str, int size, char op);
int		isnum(char *str);

// ------------ UTILS ------------ //
void	free2d(char **arr, int size);
int		find_limits(t_stack *stack, char op);
int		find_limits_n(t_stack *stack, char op);
void	sort5_xtra(t_stack *a, t_stack *b, int pos);
t_stack	*stk_cpy(t_stack *src);
int		finddex(t_stack *stack, int num);
int		lowernum(t_stack *stack, int num);

// ----------- MOVES OPS ---------- //
t_nop	best(t_stack *a, t_stack *b);
void	b2bzero(t_nop *numops);
void	movecount(t_nop *moves, t_stack *stack, int num);
void	optimizer(t_nop *numops);
int		ops_sum(t_nop *numops);
void	execute(t_stack *a, t_stack  *b, t_nop *numops);
void	execute2(t_stack *a, t_stack *b, t_nop *numops);

// ----------- STACK OPS ---------- //
t_node	*createnode(int num);
void	free_list(t_stack *stack);
void	free_lists(t_stack *a, t_stack *b);
void	stack_change(t_node *new_node, t_stack *stack);
void	initialize(t_stack *stack_a, t_stack *stack_b);
void	deathnode(t_stack *stack);

// ---------- OPERATIONS ---------- //
void	ops(t_stack *stack_a, t_stack *stack_b, char *op_id);
void	ops2(t_stack *stack_a, t_stack *stack_b, char *op_id);
int		swap(t_stack *stack_a);
int		rotate(t_stack *stack);
int		rotrot(t_stack *stack_a, t_stack *stack_b);
int		rev_rot(t_stack *stack);
int		rrr(t_stack *stack_a, t_stack *stack_b);
int		push(t_stack *src, t_stack *dest);
int		ss(t_stack *stack_a, t_stack *stack_b);

// ------------ SORT ------------ //
void	calculate(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *a, t_stack *b);
void	sort2(t_stack *stack_a, t_stack *stack_b);
void	sort3(t_stack *stk, t_stack *stk_b);
void	sort5(t_stack *stack_a, t_stack *stack_b);
#endif
