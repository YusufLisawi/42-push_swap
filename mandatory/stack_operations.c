/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:20:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 22:20:02 by yelaissa         ###   ########.fr       */
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

void	rr(t_stack *stack, int option)
{
	if (option == 'a' || option == 'r')
	{
		rotate(&stack->top_a);
		if (option == 'a')
			ft_printf("ra\n");
	}
	if (option == 'b' || option == 'r')
	{
		rotate(&stack->top_b);
		if (option == 'b')
			ft_printf("rb\n");
	}
	if (option == 'r')
		ft_printf("rr\n");
}

void	rrr(t_stack *stack, int option)
{
	if (option == 'a' || option == 'r')
	{
		reverse_rotate(&stack->top_a);
		if (option == 'a')
			ft_printf("rra\n");
	}
	if (option == 'b' || option == 'r')
	{
		reverse_rotate(&stack->top_b);
		if (option == 'b')
			ft_printf("rrb\n");
	}
	if (option == 'r')
		ft_printf("rrr\n");
}
