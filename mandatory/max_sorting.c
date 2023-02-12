/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:05:52 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:26:21 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	max_sort(t_stacks *s, int range)
{
	int	index;
	int	resize_range;

	resize_range = 0;
	while (s->a.size != 0)
	{
		index = find_index(s->sorted_a, s->a.top->content);
		if (index <= resize_range + range && index >= resize_range)
		{
			px(B, s, 1);
			resize_range++;
		}
		else if (index < resize_range)
		{
			px(B, s, 1);
			rx(B, s, 1);
			resize_range++;
		}
		else if (index > resize_range + range)
			rx(A, s, 1);
	}
	sorting_push(s);
}
