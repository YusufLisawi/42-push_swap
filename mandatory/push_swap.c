#include "push_swap.h"

int main(int ac, char **av)
{
	if (ac == 1 || check_args(av) == 0)
		return (write(2, "Error\n", 6));
	return (0);
}