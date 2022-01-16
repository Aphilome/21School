#include "ft_client.h"

void	length_sending(unsigned int length, pid_t server_pid)
{
	unsigned int	mask;

	mask = 0b10000000000000000000000000000000;
	while (mask != 0)
	{
		if ((length & mask) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(60);
		mask = mask >> 1;
	}
}

void	char_sending(const char ch, pid_t server_pid)
{
	unsigned char	mask;

	mask = 0b10000000;
	while (mask != 0)
	{
		if ((ch & mask) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(60);
		mask = mask >> 1;
	}
}

void	msg_sending(const char *msg, pid_t server_pid)
{
	while (*msg != 0)
	{
		char_sending(*msg, server_pid);
		msg++;
	}
}
