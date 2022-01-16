#include "ft_server.h"

void	exit_err_msg(void)
{
	if (g_server_mode_data.msg != NULL)
		free(g_server_mode_data.msg);
	ft_putstr_fd("Error!\n", standart_error);
	exit(0);
}
