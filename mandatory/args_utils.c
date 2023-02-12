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

#include "../includes/push_swap.h"

int	check_nums(char **nbs)
{
	int		i;
	int		j;

	i = 0;
	while (nbs[i])
	{
		if (ft_strtol(nbs[i]) > INT_MAX || ft_strtol(nbs[i]) < INT_MIN)
			return (0);
		j = 0;
		if (nbs[i][0] == '-' || nbs[i][0] == '+')
			j++;
		while (nbs[i][j])
		{
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
	int		i;
	int		j;
	char	*n1;
	char	*n2;

	i = 0;
	while (nbs[i])
	{
		j = i + 1;
		while (nbs[j])
		{
			n1 = ft_strtrim(nbs[j], "+");
			n2 = ft_strtrim(nbs[i], "+");
			if (ft_strcmp(n1, n2) == 0)
				return (0);
			j++;
			free(n1);
			free(n2);
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

void	fill_stack(t_stacks *s, char **nbs)
{
	int		i;
	t_list	*node;

	i = -1;
	while (nbs[++i])
	{
		node = ft_lstnew(ft_atoi(nbs[i]));
		ft_lstadd_back(&s->a.top, node);
		s->a.size++;
		s->sorted_a.size++;
	}
	s->sorted_a.top = copy_list(s->a.top);
	sort_list(s->sorted_a.top);
}

void	check_args(int ac, char **av, t_stacks *s)
{
	int		i;
	char	*str;
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
		str = ft_strjoin(av[i], " ");
		nbs = ft_strjoin_gnl(nbs, str);
		free(str);
	}
	nbs_arr = ft_split(nbs, ' ');
	free(nbs);
	check_exit(nbs_arr);
	fill_stack(s, nbs_arr);
	free_arr(nbs_arr);
}
