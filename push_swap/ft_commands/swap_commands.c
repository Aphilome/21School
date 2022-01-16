#include "ft_commands.h"

void	swap_a(int **array_a, t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("sa\n");
	if (array_a[0][exist] == 0 || array_a[1][exist] == 0)
		return ;
	move_array_elements(array_a, 0, 1);
}

void	swap_b(int **array_b, t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("sb\n");
	if (array_b[0][exist] == 0 || array_b[1][exist] == 0)
		return ;
	move_array_elements(array_b, 0, 1);
}

void	swap_s(int **array_a, int **array_b, t_boolean need_print)
{
	if (need_print == true)
		ft_putstr_std_output("ss\n");
	if ((array_a[0][exist] == 0 || array_a[1][exist] == 0)
		|| (array_b[0][exist] == 0 || array_b[1][exist] == 0))
		return ;
	move_array_elements(array_a, 0, 1);
	move_array_elements(array_b, 0, 1);
}
