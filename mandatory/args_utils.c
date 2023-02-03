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
/* 
	TODO:
		INT_MAX/MIN
 */
int	check_nums(char **nbs)
{
	int	i;
	int	j;

	i = 0;
	while (nbs[i])
	{
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

int	is_sorted(char **nbs)
{
	int	i;

	i = 0;
	while (nbs[i])
	{
		if (ft_atoi(nbs[i]) > ft_atoi(nbs[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int		i;
	char	*nbs;
	char	**nbs_arr;

	i = 0;
	nbs = 0;
	while (++i < ac)
		nbs = ft_strjoin_gnl(nbs, ft_strcat(av[i], " "));
	nbs_arr = ft_split(nbs, ' ');
	free(nbs);
	if (!check_nums(nbs_arr) || !check_dups(nbs_arr))
	{
		free_arr(nbs_arr);
		return (0);
	}
	free_arr(nbs_arr);
	return (1);
}
