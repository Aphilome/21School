/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:00:52 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	fill_pipe_fds(int fds[MAX_FDS][2], size_t cmd_count)
{
	size_t	i;

	i = 0;
	while (i < cmd_count - 1)
	{
		pipe(fds[i]);
		is_system_error();
		i++;
	}
}

void	close_all_pipes(int fds[MAX_FDS][2], size_t cmd_count,
						t_bool is_but, size_t but)
{
	size_t	i;

	i = 0;
	while (i < cmd_count - 1)
	{
		if (is_but == false || i != but)
		{
			try_close_fd(fds[i][0]);
			try_close_fd(fds[i][1]);
		}
		i++;
	}
}

void	pipe_write(int fd[2])
{
	try_close_fd(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	is_system_error();
}

void	pipe_read(int fd[2])
{
	try_close_fd(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	is_system_error();
}

void	close_not_used_fd(size_t i, int fds[MAX_FDS][2], size_t cmd_count)
{
	int		pos;

	pos = 0;
	if ((i % 2 == 0 && i != 0) || i % 2 != 0)
	{
		pipe_read(fds[i - 1]);
		pos = 1;
	}
	if (i != cmd_count - 1)
	{
		pipe_write(fds[i]);
		pos = 2;
	}
	if (pos == 1)
		close_all_pipes(fds, cmd_count, true, i - 1);
	else if (pos == 2)
		close_all_pipes(fds, cmd_count, true, i);
}
