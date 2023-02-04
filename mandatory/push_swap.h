/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:42:45 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 16:40:36 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	t_list	*top_a;
	t_list	*top_b;
}	t_stack;

void	check_args(int ac, char **av, t_stack *stack);
// Utils
void	free_arr(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
int		is_sorted(t_list *stack);
int		is_empty(const char *s);
void	exit_error(void);
// Stack utils
void	push(t_list **stack, int content);
int		pop(t_list **stack);
// Stack operations
void	push_to(t_stack *stack, char option);
void	swap(t_list **stack, char option);
#endif