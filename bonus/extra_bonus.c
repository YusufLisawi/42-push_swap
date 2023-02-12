/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:12:18 by yelaissa          #+#    #+#             */
/*   Updated: 2023/02/12 20:13:32 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_empty(const char *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
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
