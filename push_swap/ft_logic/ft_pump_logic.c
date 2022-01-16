#include "ft_logic.h"

t_boolean	at_least_one_flag_is_false(int **array_a, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (array_a[i][exist] == true && array_a[i][flag] == false)
			return (true);
		i++;
	}
	return (false);
}

void	pump_everything_false_into_b(int **array_a, int **array_b,
									 int length)
{
	int	i;

	i = 0;
	while (at_least_one_flag_is_false(array_a, length) == true)
	{
		if (array_a[0][flag] == false)
			push_b(array_a, array_b, length, true);
		else
			rotate_a(array_a, length, true);
		i++;
	}
}
