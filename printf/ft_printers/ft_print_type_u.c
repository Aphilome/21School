#include "ft_printers.h"

long long	ft_print_i(t_format *format, long long i_value);

long long	ft_print_u(t_format *format, long long u_value)
{
	return (ft_print_i(format, u_value));
}
