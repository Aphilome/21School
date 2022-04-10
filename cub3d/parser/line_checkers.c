/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:30:26 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/28 22:31:29 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

t_bool	is_settings_info_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] == ' ')
		i++;
	j = i;
	while (str[j] >= 'A' && str[j] <= 'Z')
		j++;
	if (i == j)
		return (false);
	i = j;
	while (str[j] == ' ')
		j++;
	if (i == j)
		return (false);
	i = j;
	while (str[j] != 0)
		j++;
	if (i == j)
		return (false);
	return (true);
}

t_bool	is_map_info_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '0' || str[i] == '1'
		|| str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		i++;
	if (i == 0 || str[i] != 0)
		return (false);
	return (true);
}

t_bool	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0 || (str[i] == '\n' && str[i + 1] == 0))
		return (true);
	return (false);
}
