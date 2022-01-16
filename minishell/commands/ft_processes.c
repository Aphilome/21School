/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:47:16 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	fill_pipe_fds(int fds[MAX_FDS][2], size_t cmd_count);
size_t	get_cmd_count(t_cmd **cmds);

t_bool	cmd_is_exit(char *input);
t_bool	cmd_is_echo(char *input);
t_bool	cmd_is_pwd(char *input);
t_bool	cmd_is_cd(char *input);
t_bool	cmd_is_export(char *input);
t_bool	cmd_is_env(char *input);
t_bool	cmd_is_unset(char *input);
void	std_exec(t_cmd *cmd, t_env_list *env);
void	save_pipe(t_cmd *cmd, int *save_fd_in, int *save_fd_out);
void	restore_pipe(t_cmd *cmd, int save_fd_in, int save_fd_out);

t_bool	more_last_child(const pid_t *children, size_t count, pid_t current,
						  pid_t new)
{
	size_t	i;

	if (current == 0)
		return (true);
	i = count - 1;
	while (i >= 0)
	{
		if (children[i] == new)
			return (true);
		if (children[i] == current)
			return (false);
		i--;
	}
	return (true);
}

void	wait_children(size_t i, pid_t *children, size_t cmd_count)
{
	pid_t	last_child_pid;
	pid_t	pid;
	int		tmp;

	last_child_pid = 0;
	while (i > 0)
	{
		pid = wait(&tmp);
		if (more_last_child(children, cmd_count, last_child_pid, pid))
		{
			last_child_pid = pid;
			g_e_bash_errno = tmp / 256;
		}
		i--;
	}
	try_free(children);
}

void	distributor(t_cmd *cmd, t_env_list **env)
{
	if (cmd_is_exit(cmd->cmd))
		ft_exit(cmd);
	else if (cmd_is_echo(cmd->cmd))
		ft_echo(cmd);
	else if (cmd_is_pwd(cmd->cmd))
		ft_pwd();
	else if (cmd_is_cd(cmd->cmd))
		ft_cd(cmd, *env);
	else if (cmd_is_export(cmd->cmd))
		ft_export(cmd, env);
	else if (cmd_is_env(cmd->cmd))
		ft_env(cmd, *env);
	else if (cmd_is_unset(cmd->cmd))
		ft_unset(cmd, env);
	else
		std_exec(cmd, *env);
}

void	work_child(size_t cmd_count, t_cmd *cmd, t_env_list **env)
{
	int		save_fd_out;
	int		save_fd_in;

	save_pipe(cmd, &save_fd_in, &save_fd_out);
	distributor(cmd, env);
	restore_pipe(cmd, save_fd_in, save_fd_out);
	if (cmd_count > 1)
		exit(g_e_bash_errno);
}

void	init_run(size_t *cmd_count, int fds[MAX_FDS][2], pid_t **children,
			t_cmd **cmds)
{
	*cmd_count = get_cmd_count(cmds);
	if (*cmd_count > 1)
	{
		fill_pipe_fds(fds, *cmd_count);
		*children = malloc(sizeof(pid_t) * (*cmd_count));
		is_system_error();
	}
	signals_off();
}
