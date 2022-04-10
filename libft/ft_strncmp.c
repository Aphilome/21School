/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:34:12 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/20 17:34:13 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*mv1;
	unsigned char	*mv2;
	size_t			i;

	mv1 = (unsigned char *)s1;
	mv2 = (unsigned char *)s2;
	i = n;
	while ((*mv1 != 0 || *mv2 != 0) && i > 0)
	{
		if (*mv1 != *mv2)
			return (*mv1 - *mv2);
		mv1++;
		mv2++;
		i--;
	}
	return (0);
}
