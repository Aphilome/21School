/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:34:31 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/20 17:34:35 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*mv;

	mv = ft_strlen(s) + (char *)s;
	while (mv >= s)
	{
		if ((char)c == *mv)
			return (mv);
		mv--;
	}
	return (NULL);
}
