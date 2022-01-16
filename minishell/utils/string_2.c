/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:25:51 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:43:07 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool	is_have_char(const char *input, const char c)
{
	size_t	i;

	if (input == NULL)
		return (false);
	i = 0;
	while (input[i] != 0)
	{
		if (input[i] == c)
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dst;
	size_t	len;

	if (is_empty(src))
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	dst = malloc(sizeof(char) * (len + 1));
	is_system_error();
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*trim(char const *str)
{
	char	*res;
	size_t	left;
	size_t	right;

	if (str == NULL)
		return (NULL);
	right = ft_strlen(str);
	left = 0;
	while (left < right && is_real_space(str[left]))
		left++;
	if (left == right)
		return (NULL);
	while (right > left && str[right - 1] == ' ')
		right--;
	res = ft_substr(str, left, right - left);
	return (res);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ((char)c + 32);
	return (c);
}

void	str_tolower(char *str)
{
	if (is_empty(str))
		return ;
	while (*str != 0)
	{
		*str = ft_tolower(*str);
		str++;
	}
}
