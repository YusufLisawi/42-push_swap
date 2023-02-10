/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:49:05 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/10 19:35:43 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_sort(t_stacks *s)
{
	if (s->a.size == 2)
	{
		ss(s, 'a');
		exit(0);
	}
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
