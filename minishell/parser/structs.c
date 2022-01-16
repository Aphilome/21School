/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:49 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 01:48:26 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_is_empty_arg(t_cmd *s, char *original);
char	*remove_extra_spaces(const char *input);
size_t	get_mines_count(const char *input);
size_t	get_flags_len(const char *input);
t_bool	is_valid(char *input);
char	*redirect_handler(char *input, size_t pos, t_cmd *cmd);
char	*dollar_handler(char *input, size_t *i, t_env_list *env);
t_bool	loop_quotes(char **trimmed, t_env_list *env);
void	show_redirects(char *data);

void	fill_struct(t_cmd *s, char *input)
{
	size_t	cmd_len;
	size_t	flags_len;

	cmd_len = ft_strlen_to_char(input, ' ');
	flags_len = get_flags_len(&(input[cmd_len]));
	s->cmd = ft_substr(input, 0, cmd_len);
	s->flags = ft_substr(input, cmd_len, flags_len);
	s->args = ft_substr(input, cmd_len + flags_len,
			ft_strlen(input) - flags_len - cmd_len);
}

void	trim_struct(t_cmd *s, char *original)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;

	tmp1 = trim(s->cmd);
	tmp2 = trim(s->flags);
	tmp3 = trim(s->args);
	try_free3(s->cmd, s->flags, s->args);
	s->cmd = tmp1;
	s->flags = tmp2;
	s->args = tmp3;
	str_tolower(s->cmd);
	set_is_empty_arg(s, original);
}

t_cmd	*get_empty_struct(void)
{
	t_cmd	*result;

	result = malloc(sizeof(t_cmd));
	is_system_error();
	result->cmd = NULL;
	result->args = NULL;
	result->flags = NULL;
	result->fd_in = STDIN_FILENO;
	result->fd_out = STDOUT_FILENO;
	result->is_empty_arg = false;
	return (result);
}

t_bool	redirect_loop(char **trimmed, t_cmd	*result)
{
	size_t	i;
	char	*tmp;

	while (true)
	{
		i = 0;
		while ((*trimmed)[i] != 0)
		{
			if ((*trimmed)[i] == '>' || (*trimmed)[i] == '<')
			{
				tmp = redirect_handler(*trimmed, i, result);
				try_free(*trimmed);
				*trimmed = tmp;
				if (is_empty(*trimmed))
				{
					try_free(result);
					return (true);
				}
				continue ;
			}
			i++;
		}
		break ;
	}
	return (false);
}

t_cmd	*get_struct(char *input, t_env_list *env)
{
	char	*trimmed;
	char	*tmp;
	t_cmd	*result;

	trimmed = trim(input);
	if (is_empty(trimmed) || !is_valid(trimmed))
	{
		try_free(trimmed);
		return (NULL);
	}
	tmp = remove_extra_spaces(trimmed);
	try_free(trimmed);
	trimmed = tmp;
	if (loop_quotes(&trimmed, env))
		return (NULL);
	result = get_empty_struct();
	if (redirect_loop(&trimmed, result))
		return (NULL);
	show_redirects(trimmed);
	fill_struct(result, trimmed);
	try_free(trimmed);
	trim_struct(result, input);
	return (result);
}
