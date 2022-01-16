/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:25:56 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_bool	try_env(t_env_list *env, char **path)
{
	*path = get_env_value("PATH", env);
	if (is_empty(*path))
	{
		try_free(*path);
		return (true);
	}
	return (false);
}

void	step_in_path(char	**paths, char *cmd, struct stat *buf, char **path)
{
	size_t	i;
	int		res;

	i = 0;
	while (paths[i] != NULL)
	{
		if (!is_empty(paths[i]))
		{
			*path = ft_strjoin_three(paths[i], "/", cmd);
			res = stat(*path, buf);
			errno = 0;
			if (res == 0)
				break ;
			try_free(*path);
			*path = NULL;
		}
		i++;
	}
}

char	*in_path(t_cmd *cmd, t_env_list *env, struct stat *buf)
{
	char	*path;
	char	**paths;
	size_t	i;

	if (try_env(env, &path))
		return (NULL);
	paths = ft_split(path, ':');
	try_free(path);
	step_in_path(paths, cmd->cmd, buf, &path);
	i = 0;
	while (paths[i] != NULL)
		try_free(paths[i++]);
	try_free(paths);
	return (path);
}

char	*in_current(t_cmd *cmd, struct stat *buf)
{
	char	*path;
	int		res;

	path = ft_strjoin("./", cmd->cmd);
	res = stat(path, buf);
	errno = 0;
	if (res == 0)
		return (path);
	try_free(path);
	return (NULL);
}
