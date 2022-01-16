#include "ft_commands.h"

void	rotate(int **array, int length)
{
	int	i;

	i = 0;
	if (array[i][exist] == 0)
		return ;
	while (i < length - 1 && array[i + 1][exist] != 0)
	{
		move_array_elements(array, i, i + 1);
		i++;
	}
}

void	rotate_a(int **array_a, int length, t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("ra\n");
	rotate(array_a, length);
}

void	rotate_b(int **array_b, int length, t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("rb\n");
	rotate(array_b, length);
}

void	rotate_ab(int **array_a, int **array_b, int length,
			t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("rr\n");
	rotate(array_a, length);
	rotate(array_b, length);
}
