#include "../libft/libft.h"

int	is_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			return (1);
		i++;
	}
	return (0);
}

int	is_allnum(char *str)
{
	char	**nums;
	int		i;
	int		j;

	nums = ft_split(str, ' ');
	i = 0;
	while (nums[i])
	{
		j = 0;
		if (nums[i][0] == '-' || nums[i][0] == '+')
			j++;
		while (nums[i][j])
		{
			if (ft_isdigit(nums[i][j]) == 0)
			{
				free(nums[i]);
				return (0);
			}
			j++;
		}
		free(nums[i]);
		i++;
	}
	free(nums);
	return (1);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (is_space(av[i]))
		{
			if (is_allnum(av[i]) == 0)
				return (0);
		}
		else
		{
			j = 0;
			if (av[i][0] == '-' || av[i][0] == '+')
				j++;
			while (av[i][j])
			{
				if (ft_isdigit(av[i][j]) == 0)
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}