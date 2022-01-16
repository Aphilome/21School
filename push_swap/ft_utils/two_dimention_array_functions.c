#include "ft_utils.h"

t_boolean	check_and_fill_array(int **mas, int length, char **argv)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < length)
	{
		if (try_get_itoa(argv[i], &tmp) == false)
			return (false);
		mas[i][value] = tmp;
		i++;
	}
	return (true);
}

void	set_params(int length, int *sort_copy_array, int **array, int need)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		array[i][flag] = false;
		array[i][exist] = need;
		i++;
	}
	i = 0;
	while (i < length)
	{
		j = 0;
		while (array[j][value] != sort_copy_array[i])
			j++;
		array[j][order] = i;
		i++;
	}
}

int	get_actual_length(int **array, int length)
{
	int	i;

	i = 0;
	while (array[i][exist] == true && i < length)
		i++;
	return (i);
}

t_boolean	is_sorted(int **array, int length)
{
	int	i;

	i = 0;
	while (i < length - 1 && array[i][exist] == true && array[i + 1][exist] ==
			  true)
	{
		if (array[i][value] > array[i + 1][value])
			return (false);
		i++;
	}
	return (true);
}

int	get_array_length(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}
