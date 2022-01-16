/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:25:51 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:58:11 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	scip_spaces(const char *str)
{
	size_t	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}

t_bool	is_real_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

t_bool	is_space(char c)
{
	if (is_real_space(c) || c == NT_SPACE)
		return (true);
	return (false);
}

t_bool	contains_end(const char *str, t_bool is_after_space)
{
	if (is_after_space)
	{
		if (*str == 0 || is_real_space(*str))
			return (true);
		return (false);
	}
	return (true);
}

t_bool	str_contains(const char *str, const char *substr, t_bool is_after_space)
{
	size_t	i;

	if (is_empty(str) || is_empty(substr))
		return (false);
	while (str != 0)
	{
		i = 0;
		while (substr[i] != 0 && *str != 0 && substr[i] == *str)
		{
			i++;
			str++;
		}
		if (substr[i] == 0)
			return (contains_end(str, is_after_space));
		if (*str == 0)
			return (false);
		str++;
	}
	return (false);
}
