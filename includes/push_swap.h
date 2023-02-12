/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:42:45 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 17:39:29 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# define A 'a'
# define B 'b'
# define S 's'
# define R 'r'

typedef struct s_stack
{
	t_list	*top;
	int		size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
	t_stack	sorted_a;
}	t_stacks;

void	check_args(int ac, char **av, t_stacks *s);
// Utils
void	free_arr(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
int		is_empty(const char *s);
void	exit_error(void);
int		is_sorted(t_list *stack);
int		is_revsorted(t_list *stack);
t_list	*copy_list(t_list *head);
void	sort_list(t_list *head);
// ------
int		find_index(t_stack s, int content);
int		min(t_stack s);
int		max(t_stack s);
// Stack utils
void	push(t_stack *stack, int content);
int		pop(t_stack *stack);
// Stack operations
void	px(char option, t_stacks *stacks);
void	swap(t_list **stack);
void	sx(int option, t_stacks *stacks);
void	rotate(t_stack *stack);
void	rx(int option, t_stacks *stacks);
void	reverse_rotate(t_list **stack);
void	rrx(int option, t_stacks *stacks);
// Sorting
void	min_sort(t_stacks *s);
void	rev_sort(t_stacks *s);
void	max_sort(t_stacks *s, int range);
#endif