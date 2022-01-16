/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:30:07 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:53:39 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_export.h"

char	**sorted_env(t_env_list *env);

char	*environment_converter(char *env)
{
	size_t	len;
	char	*left;
	char	*right;
	char	*join;

	left = NULL;
	right = NULL;
	join = NULL;
	len = ft_strlen_to_char(env, '=');
	if (ft_strlen(env) == len)
		return (ft_strjoin("declare -x ", env));
	left = ft_substr(env, 0, len + 1);
	right = ft_substr(env, len + 1, ft_strlen(env) - len + 1);
	join = ft_strjoin_three(left, "\"", right);
	try_free2(left, right);
	left = ft_strjoin_three("declare -x ", join, "\"");
	try_free(join);
	return (left);
}

t_bool	wrong_plus_place(char *input)
{
	size_t	i;

	i = ft_strlen_to_char(input, '+');
	if (i == ft_strlen(input))
		return (false);
	if (i == 0 || input[i + 1] != '=')
		return (true);
	return (false);
}

size_t	identifier_handler(char *input, t_env_list **env)
{
	size_t	i;
	char	*str;
	char	*tmp;

	i = 0;
	str = str_get_word(input);
	if (ft_isdigit(input[0]) || str[0] == '=' || wrong_plus_place(str))
	{
		tmp = ft_strjoin_three("`", str, "'");
		set_e_bash_errno(1, tmp);
		try_free(tmp);
	}
	else if (is_have_char(str, '='))
	{
		if (str_contains(str, "+=", false))
			add_new_env(str, env, true, false);
		else
			add_new_env(str, env, false, false);
	}
	else
		add_new_env(str, env, false, true);
	try_free(str);
	return (ft_strlen(str));
}

void	final_export(char **mas)
{
	size_t	i;
	char	*e;

	e = NULL;
	i = 0;
	while (mas[i] != NULL)
	{
		e = environment_converter(mas[i]);
		remove_nt_space(e);
		ft_print_str(e);
		ft_print_str("\n");
		try_free2(e, mas[i]);
		i++;
	}
}

void	ft_export(t_cmd *cmd, t_env_list **env)
{
	size_t	i;
	char	**mas;

	i = 0;
	if (cmd->args != NULL)
	{
		while (cmd->args[i] != 0)
		{
			if (is_space(cmd->args[i]) == false && cmd->args[i] != NT_SPACE)
			{
				i += identifier_handler(&(cmd->args[i]), env);
				continue ;
			}
			i++;
		}
		return ;
	}
	if (*env == NULL)
		return ;
	mas = sorted_env(*env);
	final_export(mas);
	try_free(mas);
}
