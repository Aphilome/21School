#include "utils.h"

int ft_strlen(char *msg)
{
	int i;

	i = 0;
	while (msg[i] != 0)
		i++;
	return (i);
}

void error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void print_str(char *msg)
{
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
}
