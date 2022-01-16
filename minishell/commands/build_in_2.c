/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 17:40:37 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

t_bool	cmd_is_env(char *input)
{
	return (ft_start_with(input, "env", true));
}

t_bool	cmd_is_unset(char *input)
{
	return (ft_start_with(input, "unset", true));
}
