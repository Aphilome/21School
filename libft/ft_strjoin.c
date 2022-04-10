/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:44:47 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/22 17:07:52 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*fill_malloc_by_zero(size_t size)
{
	void	*pointer;

	pointer = malloc(sizeof(char) * size);
	if (pointer != NULL)
	{
		ft_bzero(pointer, size);
		return (pointer);
	}
	return (NULL);
}

static char	*new_str_with_zero(size_t size)
{
	char	*res;

	res = fill_malloc_by_zero(sizeof(char) * (size + 1));
	return (res);
}

static char	*str2str(char *mv, const char *s)
{
	while (*s != 0)
	{
		*mv = *s;
		mv++;
		s++;
	}
	return (mv);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mv;
	char	*start;
	size_t	res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = ft_strlen(s1) + ft_strlen(s2);
	mv = new_str_with_zero(res);
	start = mv;
	if (start != NULL)
	{
		mv = str2str(mv, s1);
		mv = str2str(mv, s2);
		*mv = 0;
	}
	return (start);
}
