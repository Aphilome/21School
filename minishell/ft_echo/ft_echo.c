/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:30:29 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/30 21:28:57 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_echo.h"

void	ft_echo(t_cmd *cmd)
{
	size_t	i;

	if (cmd->args == NULL)
	{
		ft_print_str("\n");
		g_e_bash_errno = 0;
		return ;
	}
	i = 0;
	while (cmd->args[i] != 0)
	{
		if (cmd->args[i] == NT_SPACE)
			cmd->args[i] = ' ';
		i++;
	}
	ft_print_str(cmd->args);
	if (!str_contains(cmd->flags, "-n", true))
		ft_print_str("\n");
	g_e_bash_errno = 0;
}
