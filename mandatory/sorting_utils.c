/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:36:33 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 17:05:40 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_revsorted(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current->next != 0)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*copy_list(t_list *head)
{
	t_list	*new_head;
	t_list	*current;
	t_list	*temp;

	if (!head)
		return (NULL);
	new_head = ft_lstnew(head->content);
	current = head->next;
	while (current)
	{
		temp = ft_lstnew(current->content);
		ft_lstadd_back(&new_head, temp);
		current = current->next;
	}
	return (new_head);
}

void	sort_list(t_list *head)
{
	t_list	*s1;
	t_list	*s2;
	int		tmp;

	s1 = head;
	while (s1->next)
	{
		s2 = s1->next;
		while (s2)
		{
			if (s1->content > s2->content)
			{
				tmp = s1->content;
				s1->content = s2->content;
				s2->content = tmp;
			}
			s2 = s2->next;
		}
		s1 = s1->next;
	}
}
