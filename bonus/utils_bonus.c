/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:49:05 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:28:09 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_rule(char *rule, t_stacks *s)
{
	if (ft_strncmp(rule, "rra", 3) == 0)
		rrx(A, s, 0);
	else if (ft_strncmp(rule, "rrb", 3) == 0)
		rrx(B, s, 0);
	else if (ft_strncmp(rule, "rrr", 3) == 0)
		rrx(R, s, 0);
	else if (ft_strncmp(rule, "sa", 2) == 0)
		sx(A, s, 0);
	else if (ft_strncmp(rule, "sb", 2) == 0)
		sx(B, s, 0);
	else if (ft_strncmp(rule, "ss", 2) == 0)
		sx(S, s, 0);
	else if (ft_strncmp(rule, "ra", 2) == 0)
		rx(A, s, 0);
	else if (ft_strncmp(rule, "rb", 2) == 0)
		rx(B, s, 0);
	else if (ft_strncmp(rule, "rr", 2) == 0)
		rx(R, s, 0);
	else if (ft_strncmp(rule, "pa", 2) == 0)
		px(A, s, 0);
	else if (ft_strncmp(rule, "pb", 2) == 0)
		px(B, s, 0);
	else
		exit_error();
}

void	check_stack(t_stacks *s)
{
	if (is_sorted(s->a.top) && s->b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s2[i] || s1[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
