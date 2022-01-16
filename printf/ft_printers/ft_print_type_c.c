#include "ft_printers.h"

long long	ft_print_c(t_format *format, char c_value, t_boolean percent_zero)
{
	if (format->alignment == left_alignment)
	{
		ft_putchar(c_value);
		if (percent_zero == true && format->padding_with_zeros == true)
			ft_putchar_count('0', format->width - 1);
		else
			ft_putchar_count(' ', format->width - 1);
	}
	else
	{
		if (percent_zero == true && format->padding_with_zeros == true)
			ft_putchar_count('0', format->width - 1);
		else
			ft_putchar_count(' ', format->width - 1);
		ft_putchar(c_value);
	}
	return (ft_nbr_max(format->width, 1));
}
