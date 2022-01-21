#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef unsigned long long	t_ull;

typedef enum e_ret_code
{
	code_error = -1,
	code_eof = 0,
	code_readline = 1,
	code_ok = 200
}	t_ret_code;

t_ret_code	get_next_line(int fd, char **line);

#endif
