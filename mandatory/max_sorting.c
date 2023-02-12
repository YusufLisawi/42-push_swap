/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:05:52 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 17:38:44 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_push(t_stacks *s)
{
	int	index;
	int	biggest;

	while (s->b.size != 0)
	{
		biggest = max(s->b);
		index = find_index(s->b, biggest);
		if (index <= s->b.size / 2)
		{
			if (s->b.top->content == biggest)
				px(A, s);
			else
				rx(B, s);
		}
		else if (index > s->b.size / 2)
		{
			if (s->b.top->content == biggest)
				px(A, s);
			else
				rrx(B, s);
		}
	}
}

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
			px(B, s);
			resize_range++;
		}
		else if (index < resize_range)
		{
			px(B, s);
			rx(B, s);
			resize_range++;
		}
		else if (index > resize_range + range)
			rx(A, s);
	}
	sorting_push(s);
	free(s->sorted_a.top);
}
