#include "ft_printers.h"

long long	ft_print_x(t_format *format, unsigned long long x_value, t_boolean
				uppercase, t_boolean add_0x);

long long	ft_print_p(t_format *format, unsigned long long p_value)
{
	if (p_value == 0 && format->precition == 0)
	{
		if (format->alignment == left_alignment)
		{
			ft_putstr("0x");
			if (format->padding_with_zeros == true)
				ft_putchar_count('0', format->width - 2);
			else
				ft_putchar_count(' ', format->width - 2);
		}
		else
		{
			if (format->padding_with_zeros == true)
				ft_putchar_count('0', format->width - 2);
			else
				ft_putchar_count(' ', format->width - 2);
			ft_putstr("0x");
		}
		return (ft_nbr_max(format->width, 2));
	}
	return (ft_print_x(format, p_value, false, true));
}
