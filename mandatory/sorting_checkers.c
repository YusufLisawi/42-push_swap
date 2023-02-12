/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_checkers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:36:33 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 10:38:05 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next != 0)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_revsorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next != 0)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
