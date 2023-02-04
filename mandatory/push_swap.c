/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/04 12:39:53 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(int content)
{
	ft_printf("|\t%d\t|\n", content);
}

void	print_stack(t_stack stack)
{
	ft_lstiter(stack.top_a, print_lst);
	ft_printf("\033[0;31m""|\tA\t|""\033[0;37m");
	ft_printf("\n\t-\t\n");
	ft_lstiter(stack.top_b, print_lst);
	ft_printf("\033[0;32m""|\tB\t|""\033[0;37m");
}

int	main(int ac, char **av)
{
	t_stack	stack;

	check_args(ac, av, &stack);
	if (is_sorted(stack.top_a))
		return (0);
	pp(&stack, 'a');
	print_stack(stack);
	return (0);
}
