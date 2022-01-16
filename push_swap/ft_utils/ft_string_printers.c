#include "ft_utils.h"

void	ft_putchar_fd(char c, t_standart_input_output fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, t_standart_input_output fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putstr_std_error(char *s)
{
	ft_putstr_fd(s, standart_error);
}

void	ft_putstr_std_output(char *s)
{
	ft_putstr_fd(s, standart_output);
}

void	print_exit(char **clear_argv)
{
	int	i;

	i = 0;
	if (clear_argv != NULL)
	{
		while (clear_argv[i] != NULL)
		{
			free(clear_argv[i]);
			i++;
		}
	}
	ft_putstr_std_error("Error\n");
	exit(0);
}
