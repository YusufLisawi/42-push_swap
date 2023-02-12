/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:20:34 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:24:23 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	px(int option, t_stacks *stacks, int print)
{
	int		popped;

	if (option == 'b')
	{
		popped = pop(&stacks->a);
		push(&stacks->b, popped);
		if (print == 1)
			ft_printf("pb\n");
	}
	else if (option == 'a')
	{
		popped = pop(&stacks->b);
		push(&stacks->a, popped);
		if (print == 1)
			ft_printf("pa\n");
	}
}

void	sx(int option, t_stacks *stacks, int print)
{
	if (option == 'a' || option == 's')
	{
		swap(&stacks->a.top);
		if (option == 'a' && print == 1)
			ft_printf("sa\n");
	}
	if (option == 'b' || option == 's')
	{
		swap(&stacks->b.top);
		if (option == 'b' && print == 1)
			ft_printf("sb\n");
	}
	if (option == 's' && print == 1)
		ft_printf("ss\n");
}

void	rx(int option, t_stacks *stacks, int print)
{
	if (option == 'a' || option == 'r')
	{
		rotate(&stacks->a);
		if (option == 'a' && print == 1)
			ft_printf("ra\n");
	}
	if (option == 'b' || option == 'r')
	{
		rotate(&stacks->b);
		if (option == 'b' && print == 1)
			ft_printf("rb\n");
	}
	if (option == 'r' && print == 1)
		ft_printf("rr\n");
}

void	rrx(int option, t_stacks *stacks, int print)
{
	if (option == 'a' || option == 'r')
	{
		reverse_rotate(&stacks->a.top);
		if (option == 'a' && print == 1)
			ft_printf("rra\n");
	}
	if (option == 'b' || option == 'r')
	{
		reverse_rotate(&stacks->b.top);
		if (option == 'b' && print == 1)
			ft_printf("rrb\n");
	}
	if (option == 'r' && print == 1)
		ft_printf("rrr\n");
}
