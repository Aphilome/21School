/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:30:36 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:51:02 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

char	*get_current_pwd(void);
t_bool	go_to_home(t_env_list *env, int *res);
void	update_env(int res, char *old_pwd, t_env_list *env);

t_bool	is_args(t_cmd *cmd, t_env_list *env, int *res)
{
	char	*current;

	if (is_empty(cmd->args))
		return (false);
	if (cmd->args[0] == '~')
	{
		go_to_home(env, res);
		if (*res == 0 && cmd->args[1] == '/')
		{
			current = get_current_pwd();
			*res = chdir(&(cmd->args[2]));
			update_env(*res, current, env);
			try_free(current);
		}
		return (true);
	}
	current = get_current_pwd();
	*res = chdir(cmd->args);
	update_env(*res, current, env);
	try_free(current);
	return (true);
}

t_bool	is_flag(t_cmd *cmd, t_env_list *env, int *res)
{
	char	*tmp;
	char	*old_pwd;

	if (str_contains(cmd->flags, "--", true))
	{
		tmp = get_env_value("HOME", env);
		old_pwd = get_current_pwd();
		*res = chdir(tmp);
		update_env(*res, old_pwd, env);
		try_free2(tmp, old_pwd);
		return (true);
	}
	else if (str_contains(cmd->flags, "-", true))
	{
		tmp = get_env_value("OLDPWD", env);
		old_pwd = get_current_pwd();
		*res = chdir(tmp);
		update_env(*res, old_pwd, env);
		try_free2(tmp, old_pwd);
		return (true);
	}
	return (false);
}
