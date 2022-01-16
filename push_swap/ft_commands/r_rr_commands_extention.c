#include "ft_commands.h"

void	rotate_a_count(int **array_a, int length, int count)
{
	while (count > 0)
	{
		rotate_a(array_a, length, true);
		count--;
	}
}

void	rotate_b_count(int **array_b, int length, int count)
{
	while (count > 0)
	{
		rotate_b(array_b, length, true);
		count--;
	}
}

void	reverse_rotate_a_count(int **array_a, int length, int count)
{
	while (count > 0)
	{
		reverse_rotate_a(array_a, length, true);
		count--;
	}
}

void	reverse_rotate_b_count(int **array_b, int length, int count)
{
	while (count > 0)
	{
		reverse_rotate_b(array_b, length, true);
		count--;
	}
}
