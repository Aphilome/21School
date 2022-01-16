#include "ft_logic.h"

void	first_part(int **array_a, int length)
{
	if (array_a[0][order] < array_a[1][order] && array_a[1][order]
		> array_a[2][order] && array_a[2][order] > array_a[0][order])
	{
		swap_a(array_a, true);
		rotate_a(array_a, length, true);
	}
	else if (array_a[0][order] > array_a[1][order] && array_a[1][order]
		< array_a[2][order] && array_a[2][order] > array_a[0][order])
		swap_a(array_a, true);
	else if (array_a[0][order] < array_a[1][order] && array_a[1][order]
		> array_a[2][order] && array_a[2][order] < array_a[0][order])
		reverse_rotate_a(array_a, length, true);
}

void	second_part(int **array_a, int length)
{
	if (array_a[0][order] > array_a[1][order] && array_a[1][order]
		< array_a[2][order] && array_a[2][order] < array_a[0][order])
		rotate_a(array_a, length, true);
	else if (array_a[0][order] > array_a[1][order] && array_a[1][order]
		> array_a[2][order] && array_a[2][order] < array_a[0][order])
	{
		swap_a(array_a, true);
		reverse_rotate_a(array_a, length, true);
	}
}

void	ft_sort_three_elements(int **array_a, int length)
{
	if (length <= 1)
		return ;
	if (length == 2)
	{
		if (array_a[0][order] > array_a[1][order])
			swap_a(array_a, true);
		return ;
	}
	first_part(array_a, length);
	second_part(array_a, length);
}
