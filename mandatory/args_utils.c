/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   args_utils.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yelaissa <yelaissa@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/03 12:42:52 by yelaissa		  #+#	#+#			 */
/*   Updated: 2023/02/03 15:52:10 by yelaissa		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	check_nums(char **nbs)
{
	int	i;
	int	j;

	i = 0;
	while (nbs[i])
	{
		if (ft_strtol(nbs[i]) > INT_MAX || ft_strtol(nbs[i]) < INT_MIN)
			return (0);
		j = 0;
		while (nbs[i][j])
		{
			if (nbs[i][0] == '-' || nbs[i][0] == '+')
				j++;
			if (!ft_isdigit(nbs[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_dups(char **nbs)
{
	int	i;
	int	j;

	i = 0;
	while (nbs[i])
	{
		j = i + 1;
		while (nbs[j])
		{
			if (ft_strcmp(nbs[j], nbs[i]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_exit(char **nbs)
{
	if (!check_nums(nbs) || !check_dups(nbs))
	{
		free_arr(nbs);
		exit_error();
	}
}

void	fill_stack(t_stack *a, char **nbs)
{
	int		i;
	t_list	*node;

	i = -1;
	while (nbs[++i])
	{
		node = ft_lstnew(ft_atoi(nbs[i]));
		ft_lstadd_back(&a->top, node);
		a->size++;
	}
}

void	check_args(int ac, char **av, t_stack *a)
{
	int		i;
	char	*s;
	char	*nbs;
	char	**nbs_arr;

	if (ac == 1)
		exit_error();
	i = 0;
	nbs = 0;
	while (++i < ac)
	{
		if (is_empty(av[i]))
		{
			free(nbs);
			exit_error();
		}
		s = ft_strjoin(av[i], " ");
		nbs = ft_strjoin_gnl(nbs, s);
		free(s);
	}
	nbs_arr = ft_split(nbs, ' ');
	free(nbs);
	check_exit(nbs_arr);
	fill_stack(a, nbs_arr);
	free_arr(nbs_arr);
}
