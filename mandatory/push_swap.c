/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:41:51 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/05 22:51:47 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *s1, t_list *s2);

int	main(int ac, char **av)
{
	t_stacks	stacks;

	check_args(ac, av, &stacks.a);
	if (is_sorted(stacks.a.top))
		return (0);
	print_stacks(stacks.a.top, stacks.b.top);
	rrr(&stacks, 'a');
	print_stacks(stacks.a.top, stacks.b.top);
	return (0);
}

void	print_stacks(t_list *s1, t_list *s2)
{
	t_list	*temp1;
	t_list	*temp2;
	int		height1;
	int		height2;
	int		i;

	temp1 = s1;
	temp2 = s2;
	height1 = ft_lstsize(s1);
	height2 = ft_lstsize(s2);
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
}
