#include "ft_printers.h"

long long	ft_print_c(t_format *format, char c_value, t_boolean percent_zero);
long long	ft_print_s(t_format *format, char *s_value);
long long	ft_print_p(t_format *format, unsigned long long p_value);
long long	ft_print_i(t_format *format, long long i_value);
long long	ft_print_u(t_format *format, long long u_value);
long long	ft_print_x(t_format *format, unsigned long long x_value, t_boolean
				uppercase, t_boolean add_0x);
long long	ft_print_percent(t_format *format);
long long	ft_print_n(t_format *format, int *n_value);

long long	ft_print_format(t_format *format, va_list *undef_args)
{
	if (format->format_type_param == type_c)
		return (ft_print_c(format, va_arg(*undef_args, int), false));
	else if (format->format_type_param == type_s)
		return (ft_print_s(format, va_arg(*undef_args, char *)));
	else if (format->format_type_param == type_p)
		return (ft_print_p(format, va_arg(*undef_args, unsigned long long)));
	else if (format->format_type_param == type_i || format->format_type_param
		== type_d)
		return (ft_print_i(format, va_arg(*undef_args, int)));
	else if (format->format_type_param == type_u)
		return (ft_print_u(format, va_arg(*undef_args, unsigned int)));
	else if (format->format_type_param == type_x)
		return (ft_print_x(format, va_arg(*undef_args, unsigned int), false,
				false));
	else if (format->format_type_param == type_X)
		return (ft_print_x(format, va_arg(*undef_args, unsigned int), true,
				false));
	else if (format->format_type_param == type_n)
		return (ft_print_n(format, va_arg(*undef_args, int *)));
	else if (format->format_type_param == type_percent)
		return (ft_print_percent(format));
	return (0);
}
