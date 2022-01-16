/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:13:29 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	fill_pipe_fds(int fds[MAX_FDS][2], size_t cmd_count);
void	close_all_pipes(int fds[MAX_FDS][2], size_t cmd_count,
			t_bool is_but, size_t but);
void	pipe_write(int fd[2]);
void	pipe_read(int fd[2]);
void	close_not_used_fd(size_t i, int fds[MAX_FDS][2], size_t cmd_count);
t_bool	more_last_child(const pid_t *children, size_t count, pid_t current,
			pid_t new);
void	wait_children(size_t i, pid_t *children, size_t cmd_count);
void	work_child(size_t cmd_count, t_cmd *cmd, t_env_list **env);
void	init_run(size_t *cmd_count, int fds[MAX_FDS][2], pid_t **children,
			t_cmd **cmds);

size_t	get_cmd_count(t_cmd **cmds)
{
	size_t	i;

	i = 0;
	if (cmds == NULL || *cmds == NULL)
		return (0);
	while (cmds[i] != NULL)
		i++;
	return (i);
}

void	clear_cmds(t_cmd **cmds)
{
	size_t	i;

	i = 0;
	while (cmds[i] != NULL)
	{
		if (cmds[i]->fd_out != STDOUT_FILENO)
			try_close_fd(cmds[i]->fd_out);
		if (cmds[i]->fd_in != STDIN_FILENO)
			try_close_fd(cmds[i]->fd_in);
		try_free4(cmds[i]->cmd, cmds[i]->flags, cmds[i]->args, cmds[i]);
		i++;
	}
	try_free(cmds);
}

void	finalize(size_t	cmd_count, int fds[MAX_FDS][2], size_t i,
			pid_t *children)
{
	if (cmd_count <= 1)
	{
		signals_on();
		return ;
	}
	close_all_pipes(fds, cmd_count, false, 0);
	wait_children(i, children, cmd_count);
	signals_on();
}

void	parent_work(pid_t	*pid)
{
	*pid = fork();
	if (*pid < 0)
		is_system_error();
}

void	run_commands(t_cmd **cmds, t_env_list **env)
{
	size_t	i;
	pid_t	pid;
	size_t	cmd_count;
	int		fds[MAX_FDS][2];
	pid_t	*children;

	i = 0;
	init_run(&cmd_count, fds, &children, cmds);
	while (cmds[i] != NULL)
	{
		pid = 0;
		if (cmd_count > 1)
			parent_work(&pid);
		if (pid == 0)
		{
			errno = 0;
			if (cmd_count > 1)
				close_not_used_fd(i, fds, cmd_count);
			work_child(cmd_count, cmds[i], env);
		}
		else
			children[i] = pid;
		i++;
	}
	finalize(cmd_count, fds, i, children);
}
