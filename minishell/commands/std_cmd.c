/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:09 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:39:22 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

char	*in_path(t_cmd *cmd, t_env_list *env, struct stat *buf);
char	*in_current(t_cmd *cmd, struct stat *buf);
size_t	array_len(char **s);
size_t	fill_array(char **mas, char **s, size_t start);

int	run_execve(char *path, t_cmd *cmd, t_env_list *env)
{
	char	**mas;
	char	**flags;
	char	**args;
	char	**e;
	size_t	pos;

	flags = ft_split(cmd->flags, ' ');
	if (cmd->is_empty_arg)
	{
		args = malloc(sizeof(char *));
		is_system_error();
		*args = ft_strdup("\"\"");
	}
	else
		args = ft_split(cmd->args, ' ');
	mas = malloc(sizeof(char *) * (array_len(flags) + array_len(args) + 2));
	is_system_error();
	mas[0] = path;
	pos = fill_array(mas, flags, 1);
	pos = fill_array(mas, args, pos);
	try_free(flags);
	try_free(args);
	mas[pos] = NULL;
	e = get_flat_env(env, true);
	return (execve(path, mas, e));
}

t_bool	full_path(char *cmd, char **path)
{
	int			fd;

	*path = ft_strdup(cmd);
	fd = open(*path, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (errno == ENOENT)
	{
		ft_print_error("e-bash: ");
		ft_print_error(*path);
		ft_print_error(" No such file or directory\n");
		g_e_bash_errno = 127;
		errno = 0;
		try_free(*path);
		return (true);
	}
	close(fd);
	errno = 0;
	return (false);
}

void	std_finalize(char *path, t_cmd *cmd, t_env_list *env)
{
	pid_t		pid;

	pid = fork();
	if (pid < 0)
		is_system_error();
	if (pid == 0)
	{
		errno = 0;
		signals_default();
		exit(run_execve(path, cmd, env));
	}
	signals_std_on();
	try_free(path);
	waitpid(pid, &g_e_bash_errno, 0);
	signals_std_off();
	if (g_e_bash_errno == 2 || g_e_bash_errno == 3)
		g_e_bash_errno += 128;
	else
		g_e_bash_errno /= 256;
}

void	std_exec(t_cmd *cmd, t_env_list *env)
{
	char		*path;
	struct stat	buf;

	if (cmd->cmd[0] == '/')
	{
		if (full_path(cmd->cmd, &path))
			return ;
	}
	else
	{
		path = in_path(cmd, env, &buf);
		if (path == NULL)
			path = in_current(cmd, &buf);
		if (path == NULL)
		{
			set_e_bash_errno(127, cmd->cmd);
			return ;
		}
	}
	std_finalize(path, cmd, env);
}
