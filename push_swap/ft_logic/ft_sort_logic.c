#include "ft_logic.h"

int	count_ascending_order(int **array_a, int col, int length)
{
	int	i;
	int	count;
	int	max_value;

	i = col;
	count = 0;
	max_value = array_a[i][value];
	while (i + 1 < length)
	{
		if (array_a[i][value] >= max_value)
		{
			count++;
			max_value = array_a[i][value];
		}
		i++;
	}
	return (count);
}

void	put_down_flags(int **array_a, int length, int start_index)
{
	int	i;
	int	val;

	val = array_a[start_index][value];
	i = start_index;
	while (i < length)
	{
		if (array_a[i][value] >= val)
		{
			array_a[i][flag] = true;
			val = array_a[i][value];
		}
		i++;
	}
}

void	find_longest_ascending_order(int **array_a, int length)
{
	int	i;
	int	max_count;
	int	start_index;
	int	current_count;

	i = 0;
	max_count = -1;
	start_index = 0;
	while (i < length)
	{
		current_count = count_ascending_order(array_a, i, length);
		if (current_count > max_count || (current_count == max_count
				&& array_a[i][order] < array_a[start_index][order]))
		{
			start_index = i;
			max_count = current_count;
		}
		i++;
	}
	put_down_flags(array_a, length, start_index);
}
