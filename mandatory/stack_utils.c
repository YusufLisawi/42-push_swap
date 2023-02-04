/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:06:40 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 12:06:12 by yelaissa         ###   ########.fr       */
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

	if (*stack == 0)
		return (-1);
	popped = (*stack)->content;
	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
	return (popped);
}
