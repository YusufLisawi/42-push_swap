/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:20:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 20:06:30 by yelaissa         ###   ########.fr       */
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

void	ss(t_stack *stack, int option)
{
	if (option == 'a' || option == 's')
	{
		swap(&stack->top_a);
		if (option == 'a')
			ft_printf("sa\n");
	}
	if (option == 'b' || option == 's')
	{
		swap(&stack->top_b);
		if (option == 'b')
			ft_printf("sb\n");
	}
	if (option == 's')
		ft_printf("ss\n");
}
