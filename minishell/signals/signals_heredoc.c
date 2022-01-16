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

void	ctrl_c_heredoc(int signal)
{
	(void)signal;
	exit(1);
}

void	signals_heredoc(void)
{
	signal(SIGINT, ctrl_c_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
