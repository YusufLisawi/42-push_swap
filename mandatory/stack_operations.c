/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:20:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 12:43:52 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to(t_stack *stack, char type)
{
	int		popped;

	if (type == 'b')
	{
		popped = pop(&stack->top_a);
		push(&stack->top_b, popped);
		ft_printf("pb\n");
	}
	else if (type == 'a')
	{
		popped = pop(&stack->top_b);
		push(&stack->top_a, popped);
		ft_printf("pa\n");
	}
}
