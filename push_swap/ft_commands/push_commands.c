#include "ft_commands.h"

void	pa(int **array_a, int **array_b, int length)
{
	int	i;

	if (array_a[0][exist] == 1)
	{
		i = length - 1;
		while (i > 0)
		{
			shift_all_mas_elem_right(array_a, i);
			i--;
		}
		array_b[0][exist] = 0;
	}
	change_param_setter(array_a, order, array_b[0][order], 0);
	change_param_setter(array_a, flag, array_b[0][flag], 0);
	change_param_setter(array_a, value, array_b[0][value], 0);
	change_param_setter(array_a, exist, 1, 0);
	change_param_setter(array_b, exist, 0, 0);
	i = 0;
	while (array_b[i + 1][exist] == 1 && i + 1 < length)
	{
		shift_all_mas_elem_left(array_b, i);
		i++;
	}
	array_b[i][exist] = 0;
}

void	push_a(int **array_a, int **array_b, int length, t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("pa\n");
	if (array_b[0][exist] == 0)
		return ;
	pa(array_a, array_b, length);
}

void	pb(int **array_a, int **array_b, int length)
{
	int	i;

	if (array_b[0][exist] == 1)
	{
		i = length - 1;
		while (i > 0)
		{
			shift_all_mas_elem_right(array_b, i);
			i--;
		}
		array_a[0][exist] = 0;
	}
	change_param_setter(array_b, order, array_a[0][order], 0);
	change_param_setter(array_b, flag, array_a[0][flag], 0);
	change_param_setter(array_b, value, array_a[0][value], 0);
	change_param_setter(array_a, exist, 0, 0);
	change_param_setter(array_b, exist, 1, 0);
	i = 0;
	while (i + 1 < length && array_a[i + 1][exist] == 1)
	{
		shift_all_mas_elem_left(array_a, i);
		i++;
	}
	array_a[i][exist] = 0;
}

void	push_b(int **array_a, int **array_b, int length, t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("pb\n");
	if (array_a[0][exist] == 0)
		return ;
	pb(array_a, array_b, length);
}
