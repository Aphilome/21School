#include "ft_server.h"

void	server_mode_length_handler(int signum, siginfo_t *sig_info, void *t)
{
	static unsigned int	mask = 0b10000000000000000000000000000000;

	(void)t;
	g_server_mode_data.client_pid = sig_info->si_pid;
	if (signum == SIGUSR2)
		g_server_mode_data.length = g_server_mode_data.length | mask;
	mask = mask >> 1;
	if (mask == 0)
	{
		g_server_mode_data.mode = wait_msg;
		g_server_mode_data.msg = malloc(g_server_mode_data.length + 1);
		if (g_server_mode_data.msg == NULL)
			exit_err_msg();
		mask = 0b10000000000000000000000000000000;
	}
}

void	bits_and(int signum, unsigned char *c, unsigned char *mask)
{
	if (signum == SIGUSR2)
		*c = *c | *mask;
	*mask = *mask >> 1;
}

void	server_mode_msg_handler(int signum)
{
	static unsigned int		i = 0;
	static unsigned char	c = 0;
	static unsigned char	mask = 0b10000000;

	bits_and(signum, &c, &mask);
	if (mask == 0)
	{
		g_server_mode_data.msg[i] = (char)c;
		i++;
		c = 0;
		mask = 0b10000000;
		if (i == g_server_mode_data.length)
		{
			g_server_mode_data.msg[i] = 0;
			ft_putstr_fd(g_server_mode_data.msg, 1);
			ft_putstr_fd("\n", 1);
			free(g_server_mode_data.msg);
			i = 0;
			g_server_mode_data.length = 0;
			g_server_mode_data.mode = wait_length;
			if (g_server_mode_data.client_pid > 0
				&& g_server_mode_data.client_pid <= 99998)
				kill(g_server_mode_data.client_pid, SIGUSR1);
		}
	}
}

_Noreturn void	signal_distributor(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	while (1)
	{
		if (g_server_mode_data.mode == wait_length)
			sa.sa_sigaction = server_mode_length_handler;
		if (g_server_mode_data.mode == wait_msg)
			sa.sa_handler = server_mode_msg_handler;
		if (sigaction(SIGUSR1, &sa, NULL) < 0
			|| sigaction(SIGUSR2, &sa, NULL) < 0)
			exit_err_msg();
	}
}

int	main(void)
{
	g_server_mode_data.length = 0;
	g_server_mode_data.msg = NULL;
	g_server_mode_data.mode = wait_length;
	ft_putstr_fd("PID: ", 1);
	ft_print_number(getpid());
	ft_putstr_fd("\n", 1);
	signal_distributor();
}
