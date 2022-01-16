/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:29:02 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 21:02:43 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*dollar_handler(char *input, size_t *i, t_env_list *env);

char	*get_quotes_insides(char *input, char quote_type)
{
	char	*value;
	size_t	len;

	len = ft_strlen_to_char(input, quote_type);
	value = ft_substr(input, 0, len);
	len = 0;
	if (is_empty(value))
		return (value);
	while (value[len] != 0)
	{
		if (value[len] == ' ')
			value[len] = NT_SPACE;
		len++;
	}
	return (value);
}

char	*get_dollar_key(char *input)
{
	size_t	len;

	len = get_env_key_len(input);
	return (ft_substr(input, 0, len));
}

char	*double_quotes_handler(char *input, t_env_list *env)
{
	char	*value;
	char	*tmp;
	size_t	i;

	value = get_quotes_insides(input, '\"');
	i = 0;
	if (is_empty(value))
		return (value);
	while (value[i] != 0)
	{
		if (value[i] == '$')
		{
			tmp = dollar_handler(value, &i, env);
			try_free(value);
			if (is_empty(tmp))
				return (tmp);
			value = tmp;
			continue ;
		}
		i++;
	}
	return (value);
}

void	hide_redirects(char *data)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(data);
	while (i < len)
	{
		if (data[i] == '<')
			data[i] = NT_LR;
		if (data[i] == '>')
			data[i] = NT_RR;
		i++;
	}
}

char	*quote_handler(char *data, size_t *i, t_env_list *env)
{
	char	*left;
	char	*right;
	char	*middle;
	size_t	old_len;
	char	*join;

	left = ft_substr(data, 0, *i);
	if (data[*i] == '\'')
		old_len = ft_strlen_to_char(&(data[*i + 1]), '\'');
	else
		old_len = ft_strlen_to_char(&(data[*i + 1]), '\"');
	right = ft_substr(data, *i + old_len + 2,
			ft_strlen(&(data[*i + old_len + 2])));
	if (data[*i] == '\'')
		middle = get_quotes_insides(&(data[*i + 1]), '\'');
	else
		middle = double_quotes_handler(&(data[*i + 1]), env);
	*i += ft_strlen(middle);
	hide_redirects(middle);
	join = ft_strjoin(middle, right);
	try_free2(middle, right);
	middle = ft_strjoin(left, join);
	try_free2(join, left);
	return (middle);
}
