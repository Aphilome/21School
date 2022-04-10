#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	unsigned long long	i;
	char 				*s1;
	char 				*s2;
	char 				result_mas[255] = {0};

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];

		i = 0;
		while (s1[i] != 0)
		{
			if (result_mas[(int)s1[i]] == 0)
			{
				result_mas[(int)s1[i]] = 1;
				ft_putchar(s1[i]);
			}
			i++;
		}
		i = 0;
		while (s2[i] != 0)
		{
			if (result_mas[(int)s2[i]] == 0)
			{
				result_mas[(int)s2[i]] = 1;
				ft_putchar(s2[i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
