/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:33:36 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/20 17:33:39 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*mv;

	mv = (char *)s;
	while (*mv != 0)
	{
		if ((char)c == *mv)
			return (mv);
		mv++;
	}
	if ((char)c == 0)
		return (mv);
	return (NULL);
}
