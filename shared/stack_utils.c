/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:06:40 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 15:45:09 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(&stack->top, node);
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		popped;

	if (!stack->top)
		return (-1);
	popped = stack->top->content;
	tmp = stack->top;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
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

void	rotate(t_stack *stack)
{
	int	popped;

	if (!stack->top || !stack->top->next)
		return ;
	popped = pop(stack);
	ft_lstadd_back(&stack->top, ft_lstnew(popped));
	stack->size++;
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
