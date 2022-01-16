#include "ft_printers.h"

void	ft_left_alignment(t_format *format, char *s_value, long long *strlen)
{
	if (format->precition > -1)
	{
		if (format->precition < ft_strlen(s_value))
			*strlen = format->precition;
		ft_putstr_count(s_value, format->precition);
	}
	else
		ft_putstr(s_value);
	if (format->padding_with_zeros == true)
		ft_putchar_count('0', format->width - *strlen);
	else
		ft_putchar_count(' ', format->width - *strlen);
}

void	ft_right_alignment(t_format *format, char *s_value, long long *strlen)
{
	if (format->precition > -1)
	{
		if (format->precition < ft_strlen(s_value))
			*strlen = format->precition;
		if (format->padding_with_zeros == true)
			ft_putchar_count('0', format->width - *strlen);
		else
			ft_putchar_count(' ', format->width - *strlen);
		ft_putstr_count(s_value, format->precition);
	}
	else
	{
		if (format->padding_with_zeros == true)
			ft_putchar_count('0', format->width - *strlen);
		else
			ft_putchar_count(' ', format->width - *strlen);
		ft_putstr(s_value);
	}
}

long long	ft_print_s(t_format *format, char *s_value)
{
	long long	strlen;

	if (s_value == NULL)
		s_value = "(null)";
	strlen = ft_strlen(s_value);
	if (format->alignment == left_alignment)
		ft_left_alignment(format, s_value, &strlen);
	else
		ft_right_alignment(format, s_value, &strlen);
	return (ft_nbr_max(format->width, strlen));
}
