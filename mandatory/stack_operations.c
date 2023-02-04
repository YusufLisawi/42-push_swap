/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:20:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 12:40:13 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pp(t_stack *stack, char type)
{
	int		popped;

	if (type == 'a')
	{
		popped = pop(&stack->top_a);
		push(&stack->top_b, popped);
	}
	else if (type == 'b')
	{
		popped = pop(&stack->top_b);
		push(&stack->top_a, popped);
	}
}
