/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:30:16 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/30 21:32:21 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exit.h"

void	ft_exit(t_cmd *cmd)
{
	long long	num;
	char		*word;
	char		*input;

	word = ft_strjoin_three(cmd->flags, " ", cmd->args);
	input = trim(word);
	try_free(word);
	ft_print_error("exit\n");
	if (input == NULL)
		exit(g_e_bash_errno);
	num = ft_atoll(input);
	if (is_number(input))
		exit((int)((unsigned long long)num) % 256);
	word = str_get_word(input);
	if (is_number(word) == false)
	{
		set_e_bash_errno(255, input);
		exit(255);
	}
	try_free2(input, word);
	g_e_bash_errno = 1;
	ft_print_error("e-bash: exit: too many arguments\n");
}
