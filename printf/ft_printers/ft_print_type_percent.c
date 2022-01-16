#include "ft_printers.h"

long long	ft_print_c(t_format *format, char c_value, t_boolean percent_zero);

long long	ft_print_percent(t_format *format)
{
	return (ft_print_c(format, '%', true));
}
