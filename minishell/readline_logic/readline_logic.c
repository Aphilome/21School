/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:14:13 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:10:48 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_logic.h"

char	*read_cmd(void)
{
	char	*input;

	input = NULL;
	input = readline(PROMPT);
	if (errno == EINTR || errno == ENOTTY || errno == EBADF)
		errno = 0;
	is_system_error();
	return (input);
}
