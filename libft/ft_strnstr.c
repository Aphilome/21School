/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:34:27 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 22:37:47 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*src;
	char	*cut_phrase;

	i = 0;
	src = (char *) haystack;
	cut_phrase = (char *) needle;
	if (*cut_phrase == 0)
		return (src);
	needle_len = ft_strlen(needle);
	while ((src[i] != 0) && (i + needle_len <= len))
	{
		if (cut_phrase[0] == src[i])
		{
			if ((ft_strncmp(&(src[i]), needle, needle_len) == 0))
				return (&(src[i]));
		}
		i++;
	}
	return (NULL);
}
