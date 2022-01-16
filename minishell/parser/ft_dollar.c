/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:29:02 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 21:00:39 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_dollar_middle(char *input, size_t *key_len, size_t i,
			t_env_list *env)
{
	char	*key;
	char	*res;

	if (input[i + 1] == '?')
	{
		*key_len = 1;
		res = ft_itoa(g_e_bash_errno);
	}
	else
	{
		key = get_dollar_key(&(input[i + 1]));
		*key_len = ft_strlen(key);
		res = get_env_value(key, env);
		try_free(key);
	}
	return (res);
}

char	*dollar_handler(char *input, size_t *i, t_env_list *env)
{
	char	*left;
	char	*middle;
	char	*right;
	char	*result;
	size_t	key_len;

	if (input[*i + 1] == 0 || is_space(input[*i + 1]) || input[*i + 1] == '=')
	{
		*i += 1;
		return (ft_strdup(input));
	}
	left = ft_substr(input, 0, *i);
	middle = get_dollar_middle(input, &key_len, *i, env);
	right = ft_substr(input, *i + 1 + key_len,
			ft_strlen(&(input[*i + 1 + key_len])));
	result = ft_strjoin_three(left, middle, right);
	try_free3(left, middle, right);
	*i += ft_strlen(middle);
	return (result);
}
