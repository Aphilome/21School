/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:42:20 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 21:20:28 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src_buf1, const void *src_buf2, size_t count)
{
	size_t	i;
	int		diff;

	if (src_buf1 == NULL && src_buf2 == NULL)
		return (0);
	i = 0;
	while (i < count)
	{
		diff = ((unsigned char *)src_buf1)[i] - ((unsigned char *)src_buf2)[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}
