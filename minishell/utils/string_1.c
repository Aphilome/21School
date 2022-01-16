/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:25:51 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:33:58 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool	is_empty(const char *str)
{
	if (str == NULL || *str == 0)
		return (true);
	return (false);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	if (is_empty(string))
		return (0);
	i = 0;
	while (string[i] != 0)
		i++;
	return (i);
}

size_t	ft_arr_strlen(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (i);
	while (arr[i] != NULL)
		i++;
	return (i);
}

size_t	ft_strlen_to_char(const char *string, const char ch)
{
	size_t	i;

	if (is_empty(string))
		return (0);
	i = 0;
	while (string[i] != 0 && string[i] != ch)
		i++;
	return (i);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	if (len == 0 || is_empty(s))
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	is_system_error();
	if (s_len < len || s_len < start)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
