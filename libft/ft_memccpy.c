/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:02:37 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/17 21:02:38 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest_buf, const void *src_buf, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)dest_buf)[i] = ((char *)src_buf)[i];
		if (((char *)dest_buf)[i] == (char)c)
			return (&(dest_buf[i + 1]));
		i++;
	}
	return (NULL);
}
