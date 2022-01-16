#include "ft_printf.h"
#include <stdio.h> //удалить

void print_i(char *s, int a)
{
	printf(":%i\n", printf(s, a));
	ft_printf(":%i\n\n", ft_printf(s, a));
}

void ft_printf_i()
{
	print_i("01--|%10i|--", 3);
	print_i("02--|%10i|--", 38763);
	print_i("03--|%10i|--", -363);
	print_i("04--|%2i|--", -123456789);
	print_i("05--|%2i|--", 1234567890);

	print_i("06--|%010i|--", 3);
	print_i("07--|%010i|--", 38763);
	print_i("08--|%010i|--", -363);
	print_i("09--|%02i|--", -123456789);
	print_i("10--|%02i|--", 1234567890);

	print_i("11--|%010.5i|--", 3);
	print_i("12--|%010.2i|--", 38763);
	print_i("13--|%10.4i|--", -363);
	print_i("14--|%02.i|--", -123456789);
	print_i("15--|%02.10i|--", 1234567890);

	print_i("16--|%-10.5i|--", 3);
	print_i("17--|%-10.2i|--", 38763);
	print_i("18--|%-10.4i|--", -363);
	print_i("19--|%-2.i|--", -123456789);
	print_i("20--|%-2.10i|--", 1234567890);
}

void print_c(char *s, int c)
{
	printf(":%i\n", printf(s, c));
	ft_printf(":%i\n\n", ft_printf(s, c));
}

void ft_printf_c()
{
	print_c("--|%10c|--", 'a');
	print_c("--|%10c|--", 'Z');
	print_c("--|%10c|--", '8');
	print_c("--|%1c|--", 's');

	print_c("--|%-10c|--", 'a');
	print_c("--|%-10c|--", 'Z');
	print_c("--|%-10c|--", '8');
	print_c("--|%-1c|--", 's');
	print_c("--|%-1.c|--", 's');
}

void print_s(char *s, char *v)
{
	printf(":%i\n", printf(s, v));
	ft_printf(":%i\n\n", ft_printf(s, v));
}

void ft_printf_s()
{
	print_s("1--|%10s|--", "3");
	print_s("2--|%10s|--", "38763");
	print_s("3--|%10s|--", "d363");
	print_s("4--|%2s|--", "U123456789");
	print_s("5--|%2s|--", "1234567890");

	print_s("6--|%10.5s|--", "3");
	print_s("7--|%10.2s|--", "38763");
	print_s("8--|%10.4s|--", "f363");
	print_s("9--|%2.s|--", "123456789");
	print_s("10--|%2.10s|--", "1234567890");

	print_s("11--|%-10.5s|--", "3");
	print_s("12--|%-10.2s|--", "38763");
	print_s("13--|%-10.4s|--", "363");
	print_s("14--|%-2.s|--", "123456789");
	print_s("15--|%-2.10s|--", "1234567890");
}

void print_u(char *s, int a)
{
	printf(":%i\n", printf(s, a));
	ft_printf(":%i\n\n", ft_printf(s, a));
}

void ft_printf_u()
{
	print_u("01--|%10u|--", 3);
	print_u("02--|%10u|--", 38763);
	print_u("03--|%10u|--", -363);
	print_u("04--|%2u|--", -123456789);
	print_u("05--|%2u|--", 1234567890);

	print_u("06--|%010u|--", 3);
	print_u("07--|%010u|--", 38763);
	print_u("08--|%010u|--", -363);
	print_u("09--|%02u|--", -123456789);
	print_u("10--|%02u|--", 1234567890);

	print_u("11--|%010.5u|--", 3);
	print_u("12--|%010.2u|--", 38763);
	print_u("13--|%10.4u|--", -363);
	print_u("14--|%02.u|--", -123456789);
	print_u("15--|%02.10u|--", 1234567890);

	print_u("16--|%-10.5u|--", 3);
	print_u("17--|%-10.2u|--", 38763);
	print_u("18--|%-10.4u|--", -363);
	print_u("19--|%-2.u|--", -123456789);
	print_u("20--|%-2.10u|--", 1234567890);
}

void print_percent(char *s)
{
	printf(":%i\n", printf(s));
	ft_printf(":%i\n\n", ft_printf(s));
}

void ft_printf_percent()
{
	print_percent("--|%10%|--");
	print_percent("--|%10%|--");
	print_percent("--|%10%|--");
	print_percent("--|%1%|--");

	print_percent("--|%-10%|--");
	print_percent("--|%-10%|--");
	print_percent("--|%-10%|--");
	print_percent("--|%-1%|--");
	print_percent("--|%-1.%|--");
}

void print_x(char *s, long long a)
{
	printf(":%i\n", printf(s, a));
	ft_printf(":%i\n\n", ft_printf(s, a));
}

void ft_printf_x()
{
	print_x("01--|%10x|--", 3);
	print_x("02--|%10x|--", 38763);
	print_x("03--|%10x|--", -363);
	print_x("04--|%2x|--", -123456789);
	print_x("05--|%2x|--", 1234567890);

	print_x("06--|%010x|--", 3);
	print_x("07--|%010x|--", 38763);
	print_x("08--|%010x|--", -363);
	print_x("09--|%02x|--", -123456789);
	print_x("10--|%02x|--", 1234567890);

	print_x("11--|%010.5x|--", 3);
	print_x("12--|%010.2x|--", 38763);
	print_x("13--|%10.4x|--", -363);
	print_x("14--|%02.x|--", -123456789);
	print_x("15--|%02.10x|--", 1234567890);

	print_x("16--|%-10.5x|--", 3);
	print_x("17--|%-10.2x|--", 38763);
	print_x("18--|%-10.4x|--", -363);
	print_x("19--|%-2.x|--", -123456789);
	print_x("20--|%-2.10x|--", 1234567890);
}

void ft_printf_X()
{
	print_x("01--|%10X|--", 3);
	print_x("02--|%10X|--", 38763);
	print_x("03--|%10X|--", -363);
	print_x("04--|%2X|--", -123456789);
	print_x("05--|%2X|--", 1234567890);

	print_x("06--|%010X|--", 3);
	print_x("07--|%010X|--", 38763);
	print_x("08--|%010X|--", -363);
	print_x("09--|%02X|--", -123456789);
	print_x("10--|%02X|--", 1234567890);

	print_x("11--|%010.5X|--", 3);
	print_x("12--|%010.2X|--", 38763);
	print_x("13--|%10.4X|--", -363);
	print_x("14--|%02.X|--", -123456789);
	print_x("15--|%02.10X|--", 1234567890);

	print_x("16--|%-10.5X|--", 3);
	print_x("17--|%-10.2X|--", 38763);
	print_x("18--|%-10.4X|--", -363);
	print_x("19--|%-2.X|--", -123456789);
	print_x("20--|%-2.10X|--", 1234567890);
}

void print_p(char *s)
{
	int a = 1;
	printf(":%i\n", printf(s, &a));
	ft_printf(":%i\n\n", ft_printf(s, &a));
}

void ft_printf_p()
{
	print_p("01--|%20p|--");
	print_p("02--|%2p|--");
	print_p("03--|%-20p|--");
	print_p("04--|%-2p|--");
}

void ft_printf_n()
{
	int a1, a2, a3, a4;
	printf(":%i\n", printf("%n aaa%naaa  %n  %n", &a1, &a2, &a3, &a4));
	printf("%i %i %i %i\n", a1, a2, a3, a4);
	a1 = a2 = a3 = a4 = 0;
	ft_printf(":%i\n", ft_printf("%n aaa%naaa  %n  %n", &a1, &a2, &a3, &a4));
	ft_printf("%i %i %i %i\n\n", a1, a2, a3, a4);

	a1 = 0;
	printf(":%i\n", printf("%n", &a1));
	printf("%i\n", a1);
	a1 = 0;
	ft_printf(":%i\n", ft_printf("%n", &a1));
	ft_printf("%i\n\n", a1);

	printf(":%i\n", printf("-%n-", NULL));
	ft_printf(":%i\n\n", ft_printf("-%n-", NULL));
}

void ft_printf_stars()
{
	printf(":%i\n", printf("--|%*.*i|--", 10, 3, 16));
	ft_printf(":%i\n\n", ft_printf("--|%*.*i|--", 10, 3, 16));
}

int main()
{
	ft_printf_i();
//	ft_printf_c();
//	ft_printf_s();
//	ft_printf_u();
//	ft_print_x();
//	ft_printf_percent();
//	ft_printf_x();
//	ft_printf_X();
//	ft_printf_p();
//	ft_printf_n();
//ft_printf_stars();

//	printf(":%i\n", printf("%--189.43d%*.61s%-142.143u%00*.137x%070.0u" ,-1569144633,-121,"G7En;>wB,\r}k'-;u",482146913u,174,3915141126u,1733357581u));
//	ft_printf(":%i\n\n", ft_printf("%--189.43d%*.61s%-142.143u%00*.137x%070.0u" ,-1569144633,-121,"G7En;>wB,\r}k'-;u",482146913u,174,3915141126u,1733357581u));

//	printf(":%i\n", printf("%00*.13x", 17, 39151));
//	ft_printf(":%i\n\n", ft_printf("%00*.13x", 17, 39151));


	return 0;
}
