#include "ft_printf.h"

long long	ft_processing(const char *format, long long *i, t_format
*parse_res, va_list *undef_args)
{
	long long	printed_count;

	printed_count = 0;
	if (format[*i] == '%')
	{
		(*i)++;
		ft_parse_format_type(&(format[*i]), parse_res, undef_args);
		parse_res->current_index = i;
		parse_res->start_src = format;
		*i += parse_res->format_type_length - 1;
		printed_count += ft_print_format(parse_res, undef_args);
	}
	else
	{
		ft_putchar(format[*i]);
		printed_count++;
	}
	if (format[*i] != 0)
		(*i)++;
	return (printed_count);
}

int	ft_printf(const char *format, ...)
{
	long long	printed_count;
	long long	i;
	t_format	parse_res;
	va_list		undef_args;

	va_start(undef_args, format);
	printed_count = 0;
	i = 0;
	while (format[i] != 0)
		printed_count += ft_processing(format, &i, &parse_res, &undef_args);
	va_end(undef_args);
	return ((int)printed_count);
}
