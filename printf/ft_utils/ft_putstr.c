#include "ft_utils.h"

long long	ft_putstr(char *s)
{
	long long	i;

	i = 0;
	while (s[i] != 0)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

long long	ft_putstr_count(char *s, long long count)
{
	long long	i;

	i = 0;
	while (s[i] != 0 && count > 0)
	{
		ft_putchar(s[i]);
		i++;
		count--;
	}
	return (i);
}
