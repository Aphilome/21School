#include "ft_utils.h"

void	mas_clear(int ***mas, int length)
{
	while (length >= 0)
		free((*mas)[length--]);
	free(*mas);
}

t_boolean	init_sub_mas(int ***mas_a, int ***mas_b, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*mas_a)[i] = malloc(sizeof(int) * 4);
		if ((*mas_a)[i] == NULL)
		{
			mas_clear(mas_a, i - 1);
			mas_clear(mas_b, i - 1);
			return (false);
		}
		(*mas_b)[i] = malloc(sizeof(int) * 4);
		if ((*mas_b)[i] == NULL)
		{
			mas_clear(mas_a, i);
			mas_clear(mas_b, i - 1);
			return (false);
		}
		i++;
	}
	return (true);
}

t_boolean	init_mas(int ***mas_a, int **sort_copy_a, int ***mas_b, int length)
{
	*mas_a = malloc(sizeof(int *) * length);
	if (*mas_a == NULL)
		return (false);
	*mas_b = malloc(sizeof(int *) * length);
	if (*mas_b == NULL)
	{
		free(*mas_a);
		return (false);
	}
	*sort_copy_a = malloc(sizeof(int) * length);
	if (*sort_copy_a == NULL)
	{
		free(*mas_a);
		free(*mas_b);
		return (false);
	}
	if (init_sub_mas(mas_a, mas_b, length) == false)
	{
		free(*sort_copy_a);
		return (false);
	}
	return (true);
}

void	free_mas(int ***mas_a, int **sort_copy_a, int ***mas_b, int length)
{
	mas_clear(mas_a, length - 1);
	mas_clear(mas_b, length - 1);
	free(*sort_copy_a);
}

void	clear_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		free(argv[i++]);
}
