/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:55:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/10 20:15:07 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack s, int content)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = s.top;
	while (tmp->content != content && i < s.size)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_smallest(t_stack s)
{
	int		smallest;
	t_list	*tmp;

	smallest = s.top->content;
	tmp = s.top;
	while (tmp)
	{
		if (smallest > tmp->content)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	return (smallest);
}

int	find_biggest(t_stack s)
{
	int		biggest;
	t_list	*tmp;

	biggest = s.top->content;
	tmp = s.top;
	while (tmp)
	{
		if (biggest < tmp->content)
			biggest = tmp->content;
		tmp = tmp->next;
	}
	return (biggest);
}
