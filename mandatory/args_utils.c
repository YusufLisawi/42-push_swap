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
		write(2, "Error\n", 6);
		exit(0);
	}
}

void	check_args(int ac, char **av)
{
	int		i;
	char	*nbs;
	char	*s;
	char	**nbs_arr;

	if (ac == 1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	i = 0;
	nbs = 0;
	while (++i < ac)
	{
		s = ft_strjoin(av[i], " ");
		nbs = ft_strjoin_gnl(nbs, s);
		free(s);
	}
	nbs_arr = ft_split(nbs, ' ');
	free(nbs);
	check_exit(nbs_arr);
	free_arr(nbs_arr);
}
