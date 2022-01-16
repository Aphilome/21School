#include "ft_commands.h"

void	reverse_rotate_a(int **array_a, int length, t_boolean need_print)
{
	int	i;

	if (need_print == true)
		ft_putstr_std_output("rra\n");
	if (array_a[0][exist] == 0)
		return ;
	i = length - 1;
	while (array_a[i][exist] == 0)
		i--;
	while (i - 1 >= 0)
	{
		move_array_elements(array_a, i, i - 1);
		i--;
	}
}

void	reverse_rotate_b(int **array_b, int length, t_boolean need_print)
{
	int	i;

	if (need_print == true)
		ft_putstr_std_output("rrb\n");
	if (array_b[0][exist] == 0)
		return ;
	i = length - 1;
	while (array_b[i][exist] == 0)
		i--;
	while (i - 1 >= 0)
	{
		move_array_elements(array_b, i, i - 1);
		i--;
	}
}

void	reverse_rotate_ab(int **array_a, int **array_b, int length,
			t_boolean need_print)
{
	int	i;
	int	j;

	if (need_print == true)
		ft_putstr_std_output("rrr\n");
	if (array_a[0][exist] == 0 || array_b[0][exist] == 0)
		return ;
	i = length - 1;
	j = length - 1;
	while (array_a[i][exist] == 0)
		i--;
	while (i - 1 >= 0)
	{
		move_array_elements(array_a, i, i - 1);
		i--;
	}
	while (array_b[j][exist] == 0)
		j--;
	while (j - 1 >= 0)
	{
		move_array_elements(array_b, j, j - 1);
		j--;
	}
}
