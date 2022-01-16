#include "ft_printers.h"

void	ft_print_zero_or_space(t_format *format, const long long *space_count);

long long	get_precition_zero_count_x(t_format *format, const long long
*x_value_len, t_boolean add_0x)
{
	long long	zero_count;

	if (add_0x == true)
		zero_count = ft_nbr_max(format->precition - *x_value_len + 2, 0);
	else
		zero_count = ft_nbr_max(format->precition - *x_value_len, 0);
	if (format->precition == 0)
		zero_count = 0;
	return (zero_count);
}

void	ft_init_value_len(t_format *format, long long *x_value_len,
			const unsigned long long *x_value, t_boolean add_0x)
{
	*x_value_len = ft_nbr_hex_len(*x_value, add_0x);
	if (add_0x == false && (format->precition == 0 && *x_value == 0))
		*x_value_len = 0;
}

long long	ft_print_precition_x(t_format *format, const unsigned long long
*x_value, t_boolean uppercase, t_boolean add_0x)
{
	long long	zero_count;
	long long	space_count;
	long long	x_value_len;

	ft_init_value_len(format, &x_value_len, x_value, add_0x);
	zero_count = get_precition_zero_count_x(format, &x_value_len, add_0x);
	space_count = ft_nbr_max(format->width - zero_count - x_value_len, 0);
	if (format->alignment == left_alignment)
	{
		ft_putchar_count('0', zero_count);
		if (add_0x == true || (format->precition != 0 || *x_value != 0))
			ft_putnbr_hex(*x_value, uppercase, add_0x);
		ft_putchar_count(' ', space_count);
	}
	else
	{
		ft_putchar_count(' ', space_count);
		if (add_0x == true)
			ft_putstr("0x");
		ft_putchar_count('0', zero_count);
		if (add_0x == true || (format->precition != 0 || *x_value != 0))
			ft_putnbr_hex(*x_value, uppercase, false);
	}
	return (zero_count + space_count + x_value_len);
}

long long	ft_print_padding_with_zeros_x(t_format *format, const unsigned long
long *x_value, t_boolean uppercase, t_boolean add_0x)
{
	long long	space_count;
	long long	x_value_len;

	x_value_len = ft_nbr_hex_len(*x_value, add_0x);
	if (add_0x == false && (format->precition == 0 && *x_value == 0))
		x_value_len = 0;
	space_count = ft_nbr_max(format->width - x_value_len, 0);
	if (format->alignment == left_alignment)
	{
		if (add_0x == true || (format->precition != 0 || *x_value != 0))
			ft_putnbr_hex(*x_value, uppercase, add_0x);
		ft_print_zero_or_space(format, &space_count);
	}
	else
	{
		ft_print_zero_or_space(format, &space_count);
		if (add_0x == true || (format->precition != 0 || *x_value != 0))
			ft_putnbr_hex(*x_value, uppercase, add_0x);
	}
	return (space_count + x_value_len);
}

long long	ft_print_x(t_format *format, unsigned long long x_value, t_boolean
uppercase, t_boolean add_0x)
{
	if (format->precition > -1)
		return (ft_print_precition_x(format, &x_value, uppercase, add_0x));
	else
		return (ft_print_padding_with_zeros_x(format, &x_value, uppercase,
				add_0x));
}
