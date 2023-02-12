/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:49:05 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 19:06:38 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stacks *s)
{
	if (s->a.top->next->content == max(s->a) \
		&& s->a.top->content == min(s->a))
	{
		sx(A, s);
		rx(A, s);
	}
	if (s->a.top->content == max(s->a))
		rx(A, s);
	if (s->a.top->next->next->content == min(s->a))
		rrx(A, s);
	if (s->a.top->next->content == min(s->a))
		sx(A, s);
}

void	sort_five(t_stacks *s)
{
	int		smallest;

	smallest = min(s->a);
	while (s->a.top->content != smallest)
	{
		if (find_index(s->a, smallest) <= s->a.size / 2)
			rx(A, s);
		else if (find_index(s->a, smallest) > s->a.size / 2)
			rrx(A, s);
	}
	px(B, s);
	if (s->a.size != 3)
		sort_five(s);
	sort_three(s);
	while (s->b.size != 0)
		px(A, s);
}

void	min_sort(t_stacks *s)
{
	if (s->a.size == 2)
		sx(A, s);
	else if (s->a.size == 3)
		sort_three(s);
	else if (s->a.size <= 5)
		sort_five(s);
}

void	rev_sort(t_stacks *s)
{
	int	size;

	size = s->a.size;
	while (--size)
		px(B, s);
	sorting_push(s);
}
