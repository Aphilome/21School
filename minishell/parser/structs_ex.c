/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:49 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 19:00:38 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*quote_handler(char *data, size_t *i, t_env_list *env);
char	*dollar_handler(char *input, size_t *i, t_env_list *env);

void	set_is_empty_arg(t_cmd *s, char *original)
{
	size_t	i;

	if (s->args == NULL)
	{
		i = ft_strlen_to_char(original, '"');
		if (original[i] == '"')
		{
			i++;
			while (is_real_space(original[i]))
				i++;
			if (original[i] == '"')
				s->is_empty_arg = true;
		}
		if (original[i] == '\'')
		{
			i++;
			while (is_real_space(original[i]))
				i++;
			if (original[i] == '\'')
				s->is_empty_arg = true;
		}
	}
}

size_t	get_mines_count(const char *input)
{
	size_t	i;
	size_t	cnt;
	t_bool	is_flags;

	i = 0;
	cnt = 0;
	is_flags = false;
	while (input[i] != 0)
	{
		if (input[i] == '-')
		{
			is_flags = true;
			cnt++;
		}
		else if (input[i] == ' ')
			is_flags = false;
		else if (is_flags == false)
			return (cnt);
		i++;
	}
	return (cnt);
}

size_t	get_flags_len(const char *input)
{
	size_t	i;
	size_t	count;
	t_bool	is_flag;

	i = 0;
	is_flag = false;
	count = get_mines_count(input);
	while (input[i] != 0 && count > 0)
	{
		if (input[i] == '-')
			is_flag = true;
		else if (input[i] == ' ')
		{
			if (is_flag)
				count--;
			is_flag = false;
		}
		i++;
	}
	return (i);
}

t_bool	quote_detect(char **trimmed, size_t	*i, t_env_list *env)
{
	char	*tmp;

	tmp = quote_handler(*trimmed, i, env);
	try_free(*trimmed);
	*trimmed = tmp;
	if (is_empty(*trimmed))
	{
		try_free(*trimmed);
		ft_print_error("e-bash: : command not found\n");
		g_e_bash_errno = 127;
		return (true);
	}
	return (false);
}

t_bool	loop_quotes(char **trimmed, t_env_list *env)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (is_empty(*trimmed) == false && (*trimmed)[i] != 0)
	{
		if ((*trimmed)[i] == '\'' || (*trimmed)[i] == '\"')
		{
			if (quote_detect(trimmed, &i, env))
				return (true);
			continue ;
		}
		else if ((*trimmed)[i] == '$')
		{
			tmp = dollar_handler(*trimmed, &i, env);
			try_free(*trimmed);
			*trimmed = tmp;
			continue ;
		}
		i++;
	}
	return (false);
}
