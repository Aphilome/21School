/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:39:33 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 13:39:38 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	if (len == 0 || s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		error_exit(ERROR_MALLOC);
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

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*dst;
	size_t	len;

	if (src == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		error_exit(ERROR_MALLOC);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*trim(char *str)
{
	char	*res;
	size_t	left;
	size_t	right;

	if (str == NULL)
		return (NULL);
	right = ft_strlen(str);
	left = 0;
	while (left < right && str[left] == ' ')
		left++;
	if (left == right)
		return (NULL);
	while (right > left && str[right - 1] == ' ')
		right--;
	res = ft_substr(str, left, right - left);
	return (res);
}
