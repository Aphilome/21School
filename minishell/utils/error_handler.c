/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:21:46 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:29:44 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	is_system_error(void)
{
	if (errno != 0)
	{
		ft_print_error(strerror(errno));
		exit(errno);
	}
}

void	e_bash_strerror(int err, const char *prefix)
{
	if (err == 0)
		return ;
	ft_print_error("e-bash: ");
	if (prefix != NULL)
	{
		ft_print_error(prefix);
		ft_print_error(": ");
	}
	if (err == 1)
		ft_print_error("not a valid identifier\n");
	else if (err == 127)
		ft_print_error("command not found\n");
	else if (err == 255)
		ft_print_error("numeric argument required\n");
	else if (err == 258)
		ft_print_error("syntax error\n");
	else
		ft_print_error("unexpected error\n");
}

void	set_e_bash_errno(int err, const char *prefix)
{
	g_e_bash_errno = err;
	e_bash_strerror(g_e_bash_errno, prefix);
}

void	errno_2_e_bash_errno(void)
{
	if (errno == 1)
		g_e_bash_errno = 1;
	else if (errno == 2)
		g_e_bash_errno = 1;
}

t_bool	is_soft_error(const char *prefix)
{
	if (errno != 0)
	{
		errno_2_e_bash_errno();
		e_bash_strerror(g_e_bash_errno, prefix);
		errno = 0;
		return (true);
	}
	else if (g_e_bash_errno != 0)
	{
		e_bash_strerror(g_e_bash_errno, prefix);
		return (true);
	}
	return (false);
}
