#ifndef FT_CLIENT_H
# define FT_CLIENT_H

# include <signal.h>
# include <stdlib.h>
# include "../ft_string/ft_strings.h"

void	length_sending(unsigned int length, pid_t server_pid);
void	char_sending(const char ch, pid_t server_pid);
void	msg_sending(const char *msg, pid_t server_pid);

#endif
