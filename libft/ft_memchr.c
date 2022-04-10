/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:02:43 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/17 22:22:24 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src_buf, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((char *)src_buf)[i] == (char)c)
			return (&(((char *)src_buf)[i]));
		i++;
	}
	return (NULL);
}
