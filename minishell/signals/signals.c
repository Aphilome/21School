/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:34 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:28:35 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	rl_replace_line(const char *a, int b);

void	ctrl_c_handler(int signal)
{
	(void)signal;
	ft_print_str("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_e_bash_errno = 1;
}

void	signals_on(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c_handler);
}

void	signals_off(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	signals_default(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}
