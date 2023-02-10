/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:49:05 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/10 20:24:49 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *s)
{
	if (s->a.top->next->content == find_biggest(s->a) \
	&& s->a.top->content == find_smallest(s->a))
	{
		ss(s, 'a');
		rr(s, 'a');
	}
	if (s->a.top->content == find_biggest(s->a))
		rr(s, 'a');
	if (s->a.top->next->next->content == find_smallest(s->a))
		rrr(s, 'a');
	if (s->a.top->next->content == find_smallest(s->a))
		ss(s, 'a');
}

void	sort_five(t_stacks *s)
{
	int		smallest;
	t_list	*tmp;

	smallest = find_smallest(s->a);
	tmp = s->a.top;
	while (s->a.top->content != smallest)
	{
		if (find_index(s->a, smallest) <= s->a.size / 2)
			rr(s, 'a');
		else if (find_index(s->a, smallest) > s->a.size / 2)
			rrr(s, 'a');
	}
	push_to(s, 'b');
	if (s->a.size != 0)
		sort_five(s);
	while (s->b.size != 0)
		push_to(s, 'a');
}

void	min_sort(t_stacks *s)
{
	if (s->a.size == 2)
		ss(s, 'a');
	else if (s->a.size == 3)
		sort_three(s);
	else if (s->a.size <= 500)
		sort_five(s);
}
