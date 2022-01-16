/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:56 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 20:02:41 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	get_pipe_count(const char *input)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (input[i] != 0)
	{
		if (input[i] == '\'')
		{
			i += ft_strlen_to_char(&(input[i + 1]), '\'') + 2;
			continue ;
		}
		else if (input[i] == '\"')
		{
			i += ft_strlen_to_char(&(input[i + 1]), '\"') + 2;
			continue ;
		}
		else if (input[i] == '|')
			count++;
		i++;
	}
	return (count);
}

size_t	init_split(size_t *start, size_t *i, size_t	*cmd_i, char *input)
{
	*start = 0;
	*i = 0;
	*cmd_i = 0;
	return (get_pipe_count(input) + 1);
}

char	*split_pipe_detect(size_t	*start, size_t i, char *input,
						 size_t *cmds_count)
{
	char	*res;

	res = ft_substr(input, *start, i - *start);
	*start = i + 1;
	(*cmds_count)--;
	return (res);
}

char	**split_pipe(char *input)
{
	size_t	start;
	size_t	cmds_count;
	size_t	i;
	size_t	cmd_i;
	char	**mas;

	cmds_count = init_split(&start, &i, &cmd_i, input);
	mas = malloc(sizeof(char *) * (cmds_count + 1));
	is_system_error();
	while (input[i] != 0)
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			i += ft_strlen_to_char(&(input[i + 1]), input[i]) + 2;
			continue ;
		}
		else if (input[i] == '|')
			mas[cmd_i++] = split_pipe_detect(&start, i, input, &cmds_count);
		i++;
	}
	mas[cmd_i++] = ft_substr(input, start, i);
	mas[cmd_i] = NULL;
	return (mas);
}
