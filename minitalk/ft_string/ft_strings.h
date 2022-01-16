#ifndef FT_STRINGS_H
# define FT_STRINGS_H

# include <unistd.h>
//# include <stdlib.h>
//# include <signal.h>
//# include <limits.h>

typedef enum e_std_i_o_msg
{
	standart_input = 0,
	standart_output = 1,
	standart_error = 2
}	t_std_i_o_msg;

unsigned int	ft_strlen(char *str);
void			ft_putstr_fd(char *str, t_std_i_o_msg fd);
void			ft_print_number(int number);

#endif
