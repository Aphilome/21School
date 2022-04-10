//Write a program that takes two strings and displays, without doubles, the
//characters that appear in both strings, in the order they appear in the first
// one.
//
//The display will be followed by a \n.
//
//If the number of arguments is not 2, the program displays \n.
//
//Examples:
//
//$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
//		padinto$
//$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
//		df6ewg4$
//$>./inter "nothing" "This sentence hides nothing" | cat -e
//		nothig$
//$>./inter | cat -e
//		$


//Inter - получает 2 строки и надо напечатать символы которые есть в обеих
//строках (без  дублирования)

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int have_in_str(char *s, char c)
{
	while (*s != 0)
	{
		if (*s == c)
			return 1;
		s++;
	}
	return 0;
}

int main(int argc, char** argv)
{
	char *s1;
	char *s2;
	unsigned long long i;
	char alphabet[200] = {0};

	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	s1 = argv[1];
	s2 = argv[2];
	while (s1[i] != 0)
	{
		if (alphabet[s1[i]] == 0 && have_in_str(s2, s1[i]) == 1)
		{
			ft_putchar(s1[i]);
			alphabet[s1[i]] = 1;
		}
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		if (alphabet[s2[i]] == 0 && have_in_str(s1, s2[i]) == 1)
		{
			ft_putchar(s2[i]);
			alphabet[s2[i]] = 1;
		}
		i++;
	}
	return 0;
}

int main (int argc, char **argv)
{
	unsigned long long i;
	char *str1;
	char *str2;
	char alphabet[200] = {0};

	i = 0;
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
}

