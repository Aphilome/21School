#include "ft_commands.h"

void	change_param_setter(int **array, t_array_params param, int
need, int col)
{
	array[col][param] = need;
}

void	shift_all_mas_elem_left(int **array, int col)
{
	array[col][order] = array[col + 1][order];
	array[col][flag] = array[col + 1][flag];
	array[col][value] = array[col + 1][value];
	array[col][exist] = array[col + 1][exist];
	array[col + 1][exist] = 0;
}

void	shift_all_mas_elem_right(int **array, int col)
{
	array[col][order] = array[col - 1][order];
	array[col][flag] = array[col - 1][flag];
	array[col][value] = array[col - 1][value];
	array[col][exist] = array[col - 1][exist];
	array[col - 1][exist] = 0;
}

void	move_array_elements(int **array, int col1, int col2)
{
	array[col1][order] ^= array[col2][order];
	array[col2][order] ^= array[col1][order];
	array[col1][order] ^= array[col2][order];
	array[col1][flag] ^= array[col2][flag];
	array[col2][flag] ^= array[col1][flag];
	array[col1][flag] ^= array[col2][flag];
	array[col1][value] ^= array[col2][value];
	array[col2][value] ^= array[col1][value];
	array[col1][value] ^= array[col2][value];
	array[col1][exist] ^= array[col2][exist];
	array[col2][exist] ^= array[col1][exist];
	array[col1][exist] ^= array[col2][exist];
}
