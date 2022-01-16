#ifndef FT_SERVER_H
# define FT_SERVER_H

# include <signal.h>
# include <stdlib.h>
# include "../ft_string/ft_strings.h"

typedef enum e_server_mode
{
	wait_length,
	wait_msg
}	t_server_mode;

typedef struct s_server_mode_data
{
	unsigned int	length;
	char			*msg;
	t_server_mode	mode;
	pid_t			client_pid;
}	t_server_mode_data;

t_server_mode_data	g_server_mode_data;

void	exit_err_msg(void);

#endif
