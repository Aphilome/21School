/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:30:36 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:48:29 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

t_bool	is_flag(t_cmd *cmd, t_env_list *env, int *res);
t_bool	is_args(t_cmd *cmd, t_env_list *env, int *res);

char	*get_current_pwd(void)
{
	char	dir[MAXPATHLEN];

	getcwd(dir, MAXPATHLEN);
	if (errno == ENOENT)
		errno = 0;
	return (ft_strdup(dir));
}

void	update_env(int res, char *old_pwd, t_env_list *env)
{
	t_env_list	*p;
	char		*current;

	if (res != 0)
		return ;
	p = env;
	while (p != NULL)
	{
		if (ft_start_with(p->value, "OLDPWD", false))
		{
			try_free(p->value);
			p->value = ft_strjoin("OLDPWD=", old_pwd);
			p->is_hidden = false;
		}
		if (ft_start_with(p->value, "PWD", false))
		{
			try_free(p->value);
			current = get_current_pwd();
			p->value = ft_strjoin("PWD=", current);
			try_free(current);
		}
		p = p->next;
	}
}

t_bool	go_to_home(t_env_list *env, int *res)
{
	char	*tmp;
	char	*old_pwd;

	tmp = get_env_value("HOME", env);
	old_pwd = get_current_pwd();
	*res = chdir(tmp);
	update_env(*res, old_pwd, env);
	try_free2(tmp, old_pwd);
	return (true);
}

void	ft_cd(t_cmd *cmd, t_env_list *env)
{
	int	res;

	if (is_empty(cmd->args) && is_empty(cmd->flags))
		go_to_home(env, &res);
	else
		is_flag(cmd, env, &res) || is_args(cmd, env, &res);
	if (res != 0)
	{
		is_soft_error("cd: ");
		errno = 0;
	}
}
