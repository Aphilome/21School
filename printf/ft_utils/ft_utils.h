#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>

typedef enum e_boolean
{
	false,
	true
}	t_boolean;

void		ft_putchar(char c);
void		ft_putchar_count(char c, long long count);
t_boolean	ft_isdigit(int c);
long long	simple_atoi(const char *format_str, long long *start_index);
long long	ft_nbr_len(long long n);
void		ft_putnbr(long long nb);
long long	ft_nbr_hex_len(unsigned long long n, t_boolean add_0x);
void		ft_putnbr_hex(unsigned long long nb, t_boolean uppercase,
				t_boolean add_0x);
long long	ft_nbr_max(long long a, long long b);
long long	ft_putstr(char *s);
long long	ft_putstr_count(char *s, long long count);
long long	ft_strlen(char *s);

#endif
