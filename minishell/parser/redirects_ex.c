/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_ex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:29:05 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 01:47:17 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	is_file_exist(int fd, char *name);
void	run_herdoc(t_cmd *cmd, char *file);

void	is_out_redirect(t_cmd *cmd, t_bool is_double_redirect, char *file)
{
	if (cmd->fd_out != 1)
		try_close_fd(cmd->fd_out);
	if (is_double_redirect)
		cmd->fd_out = open(file, O_CREAT | O_WRONLY | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		cmd->fd_out = open(file, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	is_file_exist(cmd->fd_out, file);
}

void	is_in_redirect(t_cmd *cmd, t_bool is_double_redirect, char *file)
{
	if (cmd->fd_in != 0)
		try_close_fd(cmd->fd_in);
	if (is_double_redirect)
		run_herdoc(cmd, file);
	else
	{
		cmd->fd_in = open(file, O_RDONLY,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		is_file_exist(cmd->fd_in, file);
	}
}

char	*get_redirect_left_file(char *input, char **left, size_t pos, size_t *j)
{
	size_t	i;
	char	*file;
	char	*tmp;

	i = pos + 1;
	*left = ft_substr(input, 0, i - 1);
	if (input[pos + 1] == input[pos])
		i++;
	while (is_space(input[i]) && input[i] != NT_SPACE)
		i++;
	*j = i;
	while (is_real_space(input[*j]) == false
		   && input[*j] != '>' && input[*j] != '<' && input[*j] != 0)
		(*j)++;
	while (is_real_space(input[*j]) && input[*j] != 0)
		(*j)++;
	file = ft_substr(input, i, *j - i);
	tmp = trim(file);
	try_free(file);
	file = tmp;
	return (file);
}

void	choose_redirect(const char *input, size_t pos, t_cmd *cmd, char *file)
{
	if (input[pos] == '>')
		is_out_redirect(cmd, input[pos + 1] == input[pos], file);
	else if (input[pos] == '<')
		is_in_redirect(cmd, input[pos + 1] == input[pos], file);
	try_free(file);
}

void	show_redirects(char *data)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(data);
	while (i < len)
	{
		if (data[i] == NT_LR)
			data[i] = '<';
		if (data[i] == NT_RR)
			data[i] = '>';
		i++;
	}
}
