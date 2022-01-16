#include "ft_client.h"

void	wait_server_get_msg(int signum)
{
	if (signum != SIGUSR1)
		return ;
	ft_putstr_fd("Server has got MSG\n", 1);
	exit(0);
}

void	exit_err_msg(void)
{
	ft_putstr_fd("Error!\n", 2);
	exit(0);
}

int	ft_pid_atoi(const char *string)
{
	int			i;
	long long	pid;

	pid = 0;
	i = 0;
	while (string[i] >= '0' && string[i] <= '9')
	{
		pid = pid * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] != 0 || pid > 99998 || pid <= 0)
		return (-1);
	return ((int)pid);
}

int	ft_get_pid(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("You must give PID and MSG\n", 2);
		exit(0);
	}
	pid = ft_pid_atoi(argv[1]);
	if (pid == -1)
	{
		ft_putstr_fd("You must give correct ft_server PID\n", 2);
		exit(0);
	}
	return (pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					server_pid;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_handler = wait_server_get_msg;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		exit_err_msg();
	server_pid = ft_get_pid(argc, argv);
	if (argv[2][0] == 0)
	{
		ft_putstr_fd("You must give not empty MSG\n", standart_error);
		exit(0);
	}
	length_sending(ft_strlen(argv[2]), server_pid);
	usleep(50);
	msg_sending(argv[2], server_pid);
	usleep(10000000);
	ft_putstr_fd("Server hasn't got MSG\n", standart_error);
}
