/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:42:45 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/05 22:50:40 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
}	t_stacks;

void	check_args(int ac, char **av, t_stack *a);
// Utils
void	free_arr(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
int		is_sorted(t_list *stack);
int		is_empty(const char *s);
void	exit_error(void);
// Stack utils
void	push(t_stack *stack, int content);
int		pop(t_stack *stack);
// Stack operations
void	push_to(t_stacks *stacks, char option);
void	swap(t_list **stack);
void	ss(t_stacks *stacks, int option);
void	rotate(t_stack *stack);
void	rr(t_stacks *stacks, int option);
void	reverse_rotate(t_list **stack);
void	rrr(t_stacks *stacks, int option);
#endif