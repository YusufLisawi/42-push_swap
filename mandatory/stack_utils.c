/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:06:40 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 22:47:20 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(stack, node);
}

int	pop(t_list **stack)
{
	t_list	*tmp;
	int		popped;

	if (!*stack)
		return (-1);
	popped = (*stack)->content;
	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
	return (popped);
}

/* Swap the number at the top (ll head) 
	with the number under it (head->next) */
void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	rotate(t_list **stack)
{
	int	popped;

	if (!(*stack) || !(*stack)->next)
		return ;
	popped = pop(stack);
	ft_lstadd_back(stack, ft_lstnew(popped));
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	before_last = *stack;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
