/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:29:05 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 01:48:15 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_redirect_left_file(char *input, char **left, size_t pos,
			size_t *j);
void	choose_redirect(const char *input, size_t pos, t_cmd *cmd, char *file);

t_bool	is_file_exist(int fd, char *name)
{
	if (fd != -1)
		return (true);
	if (errno == 2)
	{
		ft_print_error("e-bash: ");
		ft_print_error(name);
		ft_print_error(": No such file or directory\n");
		errno = 0;
		g_e_bash_errno = 1;
		return (false);
	}
	is_soft_error(NULL);
	return (false);
}

void	child_heredoc_run(char *file, int herdoc[2])
{
	char	*tmp;

	errno = 0;
	signals_heredoc();
	tmp = readline("> ");
	if (errno == EINTR || errno == ENOTTY || errno == EBADF)
		errno = 0;
	is_system_error();
	while (tmp != NULL && ft_strcmp(file, tmp) != 0)
	{
		write(herdoc[1], tmp, ft_strlen(tmp));
		write(herdoc[1], "\n", 1);
		try_free(tmp);
		tmp = readline("> ");
		if (errno == EINTR || errno == ENOTTY || errno == EBADF)
			errno = 0;
		is_system_error();
	}
	try_free(tmp);
	write(herdoc[1], "\0", 1);
	exit(0);
}

void	run_herdoc(t_cmd *cmd, char *file)
{
	int		herdoc[2];
	pid_t	pid;

	pipe(herdoc);
	is_system_error();
	cmd->fd_in = herdoc[0];
	pid = fork();
	if (pid < 0)
		is_system_error();
	if (pid == 0)
		child_heredoc_run(file, herdoc);
	signals_off();
	wait(&g_e_bash_errno);
	signals_on();
	g_e_bash_errno /= 256;
	try_close_fd(herdoc[1]);
	is_system_error();
}

char	*redirect_handler(char *input, size_t pos, t_cmd *cmd)
{
	char	*res;
	char	*left;
	char	*right;
	char	*file;
	size_t	j;

	file = get_redirect_left_file(input, &left, pos, &j);
	if (file == NULL)
	{
		try_free(left);
		g_e_bash_errno = 258;
		return (NULL);
	}
	else
		remove_nt_space(file);
	choose_redirect(input, pos, cmd, file);
	if (cmd->fd_out == -1 || cmd->fd_in == -1)
	{
		try_free(left);
		return (NULL);
	}
	right = ft_substr(input, j, ft_strlen(&(input[j])));
	res = ft_strjoin(left, right);
	try_free2(left, right);
	return (res);
}
