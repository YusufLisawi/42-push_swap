/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:00:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:17:37 by yelaissa         ###   ########.fr       */
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
	char		*rule;

	init(&stacks);
	check_args(ac, av, &stacks);
	if (is_sorted(stacks.a.top))
		return (0);
	rule = get_next_line(0);
	while (rule != NULL)
	{
		exec_rule(rule, &stacks);
		rule = get_next_line(0);
	}
	check_stack(&stacks);
	return (0);
}
