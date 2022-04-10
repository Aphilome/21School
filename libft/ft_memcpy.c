/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:03:02 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/18 19:00:13 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_buf, const void *src_buf, size_t count)
{
	size_t	i;

	i = 0;
	if (dest_buf == NULL && src_buf == NULL)
		return (dest_buf);
	while (i < count)
	{
		((char *)dest_buf)[i] = ((char *)src_buf)[i];
		i++;
	}
	return (dest_buf);
}
