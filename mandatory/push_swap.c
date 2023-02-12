/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 11:28:00 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack s1, t_stack s2)
{
	t_list	*temp1;
	t_list	*temp2;
	int		height1;
	int		height2;
	int		i;

	temp1 = s1.top;
	temp2 = s2.top;
	height1 = ft_lstsize(s1.top);
	height2 = ft_lstsize(s2.top);
	i = (height1 > height2) ? height1 : height2;
	while (i >= 1)
	{
		if (i <= height1)
		{
			ft_printf("|\t%d\t|", temp1->content);
			temp1 = temp1->next;
		}
		else
			ft_printf("|\t \t|");
		if (i <= height2)
		{
			ft_printf("|\t%d\t|", temp2->content);
			temp2 = temp2->next;
		}
		else
			ft_printf("|\t \t|");
		ft_printf("      ");
		ft_printf("\n");
		i--;
	}
	ft_printf("\033[0;36m""|\tA\t||\tB\t|\n""\033[0;37m");
	ft_printf("\033[0;36m""|\t%d\t||\t%d\t|\n""\033[0;37m", s1.size, s2.size);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.a.top = 0;
	stacks.a.size = 0;
	stacks.b.top = 0;
	stacks.b.size = 0;
	check_args(ac, av, &stacks.a);
	if (is_sorted(stacks.a.top))
		return (0);
	if (stacks.a.size <= 5)
		min_sort(&stacks);
	else if (is_revsorted(stacks.a.top))
		rev_sort(&stacks);
	// print_stacks(stacks.a, stacks.b);
	return (0);
}
