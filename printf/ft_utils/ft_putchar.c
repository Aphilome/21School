#include "ft_utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_count(char c, long long count)
{
	while (count > 0)
	{
		ft_putchar(c);
		count--;
	}
}
