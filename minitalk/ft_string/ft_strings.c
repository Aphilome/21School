#include "ft_strings.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, t_std_i_o_msg fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, t_std_i_o_msg fd)
{
	if (str != NULL)
	{
		while (*str != 0)
		{
			ft_putchar_fd(*str, fd);
			str++;
		}
	}
}

void	ft_print_number(int number)
{
	char	remainder;
	int		number_div_ten;

	if (number == 0)
	{
		ft_putchar_fd('0', standart_output);
		return ;
	}
	else if (number < 0)
	{
		ft_putchar_fd('-', standart_output);
		number = -number;
	}
	number_div_ten = number / 10;
	remainder = (char)((number % 10) + '0');
	if (number_div_ten > 0)
		ft_print_number(number_div_ten);
	ft_putchar_fd(remainder, standart_output);
}
