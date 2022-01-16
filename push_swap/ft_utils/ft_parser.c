#include <limits.h>
#include "ft_utils.h"

t_boolean	ft_is_digit(int c)
{
	if (c >= 0 && c <= 9)
		return (true);
	else
		return (false);
}

t_boolean	ft_is_int(long long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (false);
	return (true);
}

void	ft_is_minus(const char *s, int *minus, int *i)
{
	if (s[0] == '-')
	{
		*minus = -1;
		i++;
	}
}

t_boolean	try_get_itoa(char *s, int *res)
{
	int			i;
	int			num;
	long long	result;
	int			minus;

	i = 0;
	result = 0;
	minus = 1;
	ft_is_minus(s, &minus, &i);
	while (s[i] != 0)
	{
		num = s[i] - '0';
		if (ft_is_digit(num) == true)
			result = result * 10 + num;
		else
			return (false);
		i++;
	}
	result *= minus;
	if (ft_is_int(result) == true)
	{
		*res = (int)result;
		return (true);
	}
	return (false);
}
