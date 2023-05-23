/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:42:02 by bbento-e          #+#    #+#             */
/*   Updated: 2023/05/23 17:46:56 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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


#endif
