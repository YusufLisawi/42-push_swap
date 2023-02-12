/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 17:56:13 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_stacks *s)
{
	s->a.top = 0;
	s->a.size = 0;
	s->b.top = 0;
	s->b.size = 0;
	s->sorted_a.top = 0;
	s->sorted_a.size = 0;
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	init(&stacks);
	check_args(ac, av, &stacks);
	if (is_sorted(stacks.a.top))
		return (0);
	if (stacks.a.size <= 5)
		min_sort(&stacks);
	else if (is_revsorted(stacks.a.top))
		rev_sort(&stacks);
	else if (stacks.a.size <= 100)
		max_sort(&stacks, 12);
	else if (stacks.a.size <= 500)
		max_sort(&stacks, 25);
	return (0);
}
