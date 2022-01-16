#include "ft_utils.h"

void	fill_array_param(int length, int *array, int **src_array,
						 t_array_params param)
{
	int	i;

	i = 0;
	while (i < length)
	{
		array[i] = src_array[i][param];
		i++;
	}
}

void	sort_array(int length, int *array)
{
	int	l;
	int	i;

	l = length;
	while (l > 0)
	{
		i = 0;
		while (i < l - 1)
		{
			if (array[i] >= array[i + 1])
			{
				array[i] ^= array[i + 1];
				array[i + 1] ^= array[i];
				array[i] ^= array[i + 1];
			}
			i++;
		}
		l--;
	}
}

t_boolean	ft_check_duplicates(const int *sorted_array, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (sorted_array[i] == sorted_array[i + 1])
			return (true);
		i++;
	}
	return (false);
}
