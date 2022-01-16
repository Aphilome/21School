#include "ft_printers.h"

long long	ft_print_n(t_format *format, int *n_value)
{
	long long	count_n;
	long long	i;

	count_n = 0;
	i = 0;
	if (n_value != NULL)
	{
		while (i < *(format->current_index) - 1)
		{
			if (format->start_src[i] == '%' && format->start_src[i + 1] == 'n')
				count_n++;
			i++;
		}
		*n_value = (int)(*(format->current_index) - 1 - (2 * count_n));
	}
	return (0);
}
