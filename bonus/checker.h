/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:42:02 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/24 11:24:24 by bbento-e         ###   ########.fr       */
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
int		check_order(char **str, int size);
int		dups(char **str, int size, char op);

// --------------- UTILS --------------- //
int		sender(char type);
int		size2d(char **str);
t_node	*createnode(int num);
void	deathnode(t_stack *stack);
void	free_lists(t_stack *a, t_stack *b);
int		free2d(char **arr, int size, char type);
void	stack_change(t_node *new_node, t_stack *stack);
#endif
