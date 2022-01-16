/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_ex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:06 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 16:05:35 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

size_t		ft_env_lstsize(t_env_list *lst);

char	*get_env_value(char *key, t_env_list *env)
{
	size_t		len;
	t_env_list	*p;

	if (ft_isdigit(key[0]) == true)
		return (ft_strdup(""));
	len = ft_strlen(key);
	p = env;
	while (p != NULL)
	{
		if (ft_start_with(p->value, key, false))
		{
			if ((p->value)[len] != '=')
				continue ;
			return (ft_substr(p->value, len + 1, ft_strlen(p->value) - len));
		}
		p = p->next;
	}
	return (ft_strdup(""));
}

void	print_environment(t_env_list *env)
{
	t_env_list	*p;
	char		*tmp;

	p = env;
	while (p != NULL)
	{
		if (!p->is_hidden)
		{
			tmp = ft_strdup(p->value);
			remove_nt_space(tmp);
			ft_print_str(tmp);
			ft_print_str("\n");
			try_free(tmp);
		}
		p = p->next;
	}
}

char	**get_flat_env(t_env_list *env, t_bool copy)
{
	char		**mas;
	t_env_list	*p;
	size_t		i;

	mas = malloc(sizeof(char *) * (ft_env_lstsize(env) + 1));
	is_system_error();
	i = 0;
	p = env;
	while (p != NULL)
	{
		if (copy)
			mas[i++] = ft_strdup(p->value);
		else
			mas[i++] = p->value;
		p = p->next;
	}
	mas[i] = NULL;
	return (mas);
}

char	*env_adapter(char *env, t_bool *is_hidden)
{
	int		sh_lvl;
	char	*tmp;

	*is_hidden = false;
	if (ft_start_with(env, "OLDPWD=", false))
	{
		*is_hidden = true;
		return (ft_strdup("OLDPWD"));
	}
	else if (ft_start_with(env, "SHLVL=", false))
	{
		tmp = ft_substr(env, 6, ft_strlen(&(env[6])));
		sh_lvl = ft_atoi(tmp) + 1;
		try_free(tmp);
		tmp = ft_itoa(sh_lvl);
		env = ft_strjoin("SHLVL=", tmp);
		try_free(tmp);
		return (env);
	}
	return (ft_strdup(env));
}

size_t	get_env_key_len(char *str)
{
	size_t	len;

	len = 0;
	if (ft_isdigit(str[0]) == true)
		return (1);
	while ((ft_str_is_alpha(str[len]) || ft_str_is_num(str[len]))
		   && str[len] != 0)
		len++;
	return (len);
}
