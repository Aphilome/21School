/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:47:03 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	save_pipe(t_cmd *cmd, int *save_fd_in, int *save_fd_out)
{
	if (cmd->fd_out != STDOUT_FILENO)
	{
		*save_fd_out = dup(STDOUT_FILENO);
		dup2(cmd->fd_out, STDOUT_FILENO);
	}
	if (cmd->fd_in != STDIN_FILENO)
	{
		*save_fd_in = dup(STDIN_FILENO);
		dup2(cmd->fd_in, STDIN_FILENO);
	}
}

void	restore_pipe(t_cmd *cmd, int save_fd_in, int save_fd_out)
{
	if (cmd->fd_out != STDOUT_FILENO)
	{
		dup2(save_fd_out, STDOUT_FILENO);
		try_close_fd(save_fd_out);
	}
	if (cmd->fd_in != STDIN_FILENO)
	{
		dup2(save_fd_in, STDIN_FILENO);
		try_close_fd(save_fd_in);
	}
}
