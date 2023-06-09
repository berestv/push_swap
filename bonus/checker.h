/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:42:02 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/30 12:29:35 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
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

// --------------- VERIF --------------- //
int		isnum(char *str);
int		dups(char **str, int size);
int		check_order_list(t_stack *stack);

// --------------- UTILS --------------- //
int		sender(char type);
int		size2d(char **str);
t_node	*createnode(int num);
void	free_list(t_stack *a);
t_stack	*stk_cpy(t_stack *src);
void	deathnode(t_stack *stack);
int		exec_ops(t_stack *a, t_stack *b);
int		free_lists(t_stack *a, t_stack *b);
int		free2d(char **arr, int size, char type);
void	stack_change(t_node *new_node, t_stack *stack);

// ---------- OPERATIONS ---------- //
int		swap(t_stack *stack_a);
int		rotate(t_stack *stack);
int		rev_rot(t_stack *stack);
int		push(t_stack *src, t_stack *dest);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		rrr(t_stack *stack_a, t_stack *stack_b);
int		rotrot(t_stack *stack_a, t_stack *stack_b);
int		ops(t_stack *stack_a, t_stack *stack_b, char *op_id);
int		ops2(t_stack *stack_a, t_stack *stack_b, char *op_id);

#endif
