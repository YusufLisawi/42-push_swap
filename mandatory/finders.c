/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:55:14 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 10:37:45 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	min(t_stack s)
{
	int		min;
	t_list	*tmp;

	min = s.top->content;
	tmp = s.top;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	max(t_stack s)
{
	int		max;
	t_list	*tmp;

	max = s.top->content;
	tmp = s.top;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}
