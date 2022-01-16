#include "ft_logic.h"

int	ft_how_much_do_rotate_in_a(int **array_a)
{
	int	i;

	i = 0;
	while (array_a[i][order] != 0)
		i++;
	return (i);
}

void	do_rotate_in_a(int **array_a, int length)
{
	int	r_a;
	int	r_r_a;

	r_a = ft_how_much_do_rotate_in_a(array_a);
	r_r_a = length - r_a;
	if (r_a < r_r_a)
		rotate_a_count(array_a, length, r_a);
	else
		reverse_rotate_a_count(array_a, length, r_r_a);
}
