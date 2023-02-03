/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/03 21:42:42 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(int content)
{
	ft_printf("| %d | \n", content);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	check_args(ac, av, &stack);
	ft_lstiter(stack.top_a, print_lst);
	return (0);
}
