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

void	ctrl_backslash_default(int signal)
{
	(void)signal;
	ft_print_str("Quit: 3\n");
}

void	signals_std_on(void)
{
	signal(SIGQUIT, ctrl_backslash_default);
}

void	signals_std_off(void)
{
	signal(SIGQUIT, SIG_IGN);
}
