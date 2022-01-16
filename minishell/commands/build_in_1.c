/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 17:32:38 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_bool	cmd_is_exit(char *input)
{
	return (ft_start_with(input, "exit", true));
}

t_bool	cmd_is_echo(char *input)
{
	return (ft_start_with(input, "echo", true));
}

t_bool	cmd_is_pwd(char *input)
{
	return (ft_start_with(input, "pwd", true));
}

t_bool	cmd_is_cd(char *input)
{
	return (ft_start_with(input, "cd", true));
}

t_bool	cmd_is_export(char *input)
{
	return (ft_start_with(input, "export", true));
}
