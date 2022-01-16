#include "ft_printers.h"

void	ft_print_zero_or_space(t_format *format, const long long *space_count)
{
	if (format->padding_with_zeros == true)
		ft_putchar_count('0', *space_count);
	else
		ft_putchar_count(' ', *space_count);
}
