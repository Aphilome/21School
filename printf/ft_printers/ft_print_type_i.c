#include "ft_printers.h"

void	ft_print_zero_or_space(t_format *format, const long long *space_count);

void	ft_print_and_invert_value(t_format *format, long long *i_value,
			const long long *zero_count)
{
	if (*i_value < 0)
	{
		*i_value = -(*i_value);
		ft_putchar('-');
	}
	ft_putchar_count('0', *zero_count);
	if (format->precition != 0 || *i_value != 0)
		ft_putnbr(*i_value);
}

long long	get_precition_zero_count_i(t_format *format, const long long
*i_value, const long long *i_value_len)
{
	long long	zero_count;

	zero_count = format->precition - *i_value_len;
	if (*i_value < 0)
		zero_count = ft_nbr_max(zero_count + 1, 0);
	if (format->precition == 0)
		zero_count = 0;
	return (ft_nbr_max(zero_count, 0));
}

long long	ft_print_precition_i(t_format *format, long long *i_value)
{
	long long	zero_count;
	long long	space_count;
	long long	i_value_len;

	if (format->print_space == true)
		ft_putchar(' ');
	i_value_len = ft_nbr_len(*i_value);
	if (format->precition == 0 && *i_value == 0)
		i_value_len = 0;
	zero_count = get_precition_zero_count_i(format, i_value, &i_value_len);
	space_count = ft_nbr_max(format->width - zero_count - i_value_len, 0);
	if (format->alignment == left_alignment)
	{
		ft_print_and_invert_value(format, i_value, &zero_count);
		ft_putchar_count(' ', space_count);
	}
	else
	{
		ft_putchar_count(' ', space_count);
		ft_print_and_invert_value(format, i_value, &zero_count);
	}
	if (format->print_space == true)
		i_value_len++;
	return (zero_count + space_count + i_value_len);
}

long long	ft_print_padding_with_zeros(t_format *format, long long *i_value)
{
	long long	space_count;
	long long	i_value_len;

	i_value_len = ft_nbr_len(*i_value);
	if (format->precition == 0 && *i_value == 0)
		i_value_len = 0;
	space_count = ft_nbr_max(format->width - i_value_len, 0);
	if (format->alignment == left_alignment)
	{
		if (format->precition != 0 || *i_value != 0)
			ft_putnbr(*i_value);
		ft_print_zero_or_space(format, &space_count);
	}
	else
	{
		if (*i_value < 0 && format->padding_with_zeros == true)
		{
			ft_putchar('-');
			*i_value = -(*i_value);
		}
		ft_print_zero_or_space(format, &space_count);
		if (format->precition != 0 || *i_value != 0)
			ft_putnbr(*i_value);
	}
	return (space_count + i_value_len);
}

long long	ft_print_i(t_format *format, long long i_value)
{
	if (format->precition > -1)
		return (ft_print_precition_i(format, &i_value));
	else
		return (ft_print_padding_with_zeros(format, &i_value));
}
