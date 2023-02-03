/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:06:40 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/03 22:53:04 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack, int popped)
{
	t_list	*node;

	node = ft_lstnew(popped);
	ft_lstadd_front(stack, node);
}

int	pop(t_stack *stack)
{
	t_list	*tmp;
	int		popped;

	if (stack->top_a == 0)
		return (-1);
	popped = stack->top_a->content;
	tmp = stack->top_a;
	stack->top_a = tmp->next;
	free(tmp);
	return (popped);
}
