/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:49 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 21:02:30 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	is_valid(char *input);
t_bool	is_bordered_with_pipe(char *input);
char	*dollar_handler(char *input, size_t *i, t_env_list *env);
char	**split_pipe(char *input);
void	fill_struct(t_cmd *s, char *input);
void	trim_struct(t_cmd *s, char *original);
t_cmd	*get_empty_struct(void);
t_cmd	*get_struct(char *input, t_env_list *env);

void	detect_extra_space(size_t i, char	**result)
{
	size_t	j;
	char	*left;
	char	*right;
	char	*tmp;

	j = i + 1;
	while ((*result)[j] == ' ')
		j++;
	left = ft_substr(*result, 0, i + 1);
	right = ft_substr(*result, j, ft_strlen(&((*result)[j])));
	tmp = ft_strjoin(left, right);
	try_free3(left, right, *result);
	*result = tmp;
}

char	*remove_extra_spaces(const char *input)
{
	size_t	i;
	char	*result;

	i = 0;
	result = ft_strdup(input);
	while (result[i] != 0)
	{
		if (result[i] == '\'')
		{
			i += ft_strlen_to_char(&(result[i + 1]), '\'') + 2;
			continue ;
		}
		if (result[i] == '\"')
		{
			i += ft_strlen_to_char(&(result[i + 1]), '\"') + 2;
			continue ;
		}
		if (result[i] == ' ' && result[i + 1] == ' ')
			detect_extra_space(i, &result);
		i++;
	}
	return (result);
}

void	roll_back(t_cmd **cmds, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		try_free4(cmds[i]->cmd, cmds[i]->args, cmds[i]->flags, cmds[i]);
		i++;
	}
}

t_bool	create_loop(char **piped_cmds, t_cmd **cmds, t_env_list *env)
{
	size_t	i;

	i = 0;
	while (piped_cmds[i] != NULL)
	{
		cmds[i] = get_struct(piped_cmds[i], env);
		try_free(piped_cmds[i]);
		if (cmds[i] == NULL)
		{
			roll_back(cmds, i);
			try_free2(piped_cmds, cmds);
			return (true);
		}
		i++;
	}
	try_free(piped_cmds);
	cmds[i] = NULL;
	return (false);
}

t_cmd	**create_commands(char *input, t_env_list *env)
{
	size_t	piped_cmds_count;
	char	**piped_cmds;
	t_cmd	**cmds;

	if (is_bordered_with_pipe(input))
	{
		ft_print_error("e-bash: syntax error near unexpected token `|'\n");
		g_e_bash_errno = 2;
		return (NULL);
	}
	if (!is_valid(input))
		return (NULL);
	piped_cmds = split_pipe(input);
	piped_cmds_count = ft_arr_strlen(piped_cmds);
	if (piped_cmds_count == 0)
		return (NULL);
	cmds = malloc(sizeof(t_cmd *) * (piped_cmds_count + 1));
	is_system_error();
	if (create_loop(piped_cmds, cmds, env))
		return (NULL);
	return (cmds);
}
