#include "ft_utils.h"

long long	simple_atoi(const char *format_str, long long *start_index)
{
	long long	res;

	res = 0;
	while (ft_isdigit(format_str[*start_index]) == true)
	{
		res = res * 10 + format_str[*start_index] - '0';
		(*start_index)++;
	}
	return (res);
}
