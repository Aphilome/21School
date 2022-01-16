#include "ft_utils.h"

long long	ft_nbr_max(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	ft_nbr_len(long long n)
{
	long long	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(long long nb)
{
	char	mod;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	mod = (char)(nb % 10 + '0');
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	ft_putchar(mod);
}

long long	ft_nbr_hex_len(unsigned long long n, t_boolean add_0x)
{
	long long	len;

	if (n == 0)
	{
		if (add_0x == true)
			return (3);
		return (1);
	}
	len = 1;
	while (n / 16 > 0)
	{
		n = (n / 16);
		len++;
	}
	if (add_0x == true)
		len += 2;
	return (len);
}

void	ft_putnbr_hex(unsigned long long nb, t_boolean uppercase, t_boolean
add_0x)
{
	char	mod;

	if (add_0x == true)
		ft_putstr("0x");
	mod = (char)(nb % 16);
	if (mod >= 0 && mod <= 9)
		mod += '0';
	else
	{
		if (uppercase == true)
			mod += 55;
		else
			mod += 87;
	}
	if (nb / 16 != 0)
		ft_putnbr_hex(nb / 16, uppercase, false);
	ft_putchar(mod);
}
