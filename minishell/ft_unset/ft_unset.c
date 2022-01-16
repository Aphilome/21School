/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:29:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:54:47 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unset.h"

size_t	identifier_unset_handler(char *input, t_env_list **env)
{
	char	*str;
	char	*tmp;
	size_t	len;

	str = str_get_word(input);
	if (ft_isdigit(input[0])
		|| is_have_char(str, '=')
		|| is_have_char(str, '+'))
	{
		tmp = ft_strjoin_three("`", str, "'");
		set_e_bash_errno(1, tmp);
		try_free(tmp);
	}
	else
		del_env(str, env);
	len = ft_strlen(str);
	try_free(str);
	return (len);
}

void	ft_unset(t_cmd *cmd, t_env_list **env)
{
	size_t	i;

	if (cmd->args == NULL)
		return ;
	i = 0;
	while (cmd->args[i] != 0)
	{
		if (is_space(cmd->args[i]) == false)
		{
			i += identifier_unset_handler(&(cmd->args[i]), env);
			continue ;
		}
		i++;
	}
}
