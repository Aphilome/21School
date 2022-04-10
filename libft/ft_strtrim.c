/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:05:56 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/21 20:03:15 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	left;

	if (s1 == NULL)
		return (NULL);
	left = ft_strlen(s1);
	i = 0;
	if (set != NULL)
	{
		while (i < left && ft_strchr(set, s1[i]) != 0)
			i++;
		while (left > i && ft_strchr(set, s1[left - 1]) != 0)
			left--;
		res = ft_substr(s1, i, left - i);
		return (res);
	}
	return (NULL);
}
