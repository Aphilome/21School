//subj
/*

 Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

 */


void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char** argv)
{
	char alphabet[200] = {0};
	char *s1;
	char *s2;

	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	while (*s1 != 0)
	{
		if (alphabet[*s1] == 0)
		{
			ft_putchar(*s1);
			alphabet[*s1] = 1;
		}
		s1++;
	}
	while (*s2 != 0)
	{
		if (alphabet[*s2] == 0)
		{
			ft_putchar(*s2);
			alphabet[*s2] = 1;
		}
		s2++;
	}
	return 0;
}


#include <unistd.h>



// тест
/*
gcc -Wall -Werror -Wextra union.c -o union
echo "# Expected result (next line) Your result #"
echo "---"
echo "zpadintoqefwjy$"
./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
echo "---"
echo "df6vewg4thras$"
./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
echo "---"
echo "rienct phas$"
./union "rien" "cette phrase ne cache rien" | cat -e
echo "---"
echo "$"
./union | cat -e
echo "---"
echo "$"
./union "rien" | cat -e
rm -rf union
 */
