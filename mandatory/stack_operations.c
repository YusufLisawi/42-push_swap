/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:20:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 18:20:40 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_stack *stack, char option)
{
	int		popped;

	if (option == 'b')
	{
		popped = pop(&stack->top_a);
		push(&stack->top_b, popped);
		ft_printf("pb\n");
	}
	else if (option == 'a')
	{
		popped = pop(&stack->top_b);
		push(&stack->top_a, popped);
		ft_printf("pa\n");
	}
}

void	swap(t_list **stack, char option)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (option)
		ft_printf("s%c\n", option);
}
