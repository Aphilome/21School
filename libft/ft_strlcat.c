/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:42:26 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 22:31:59 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] != 0 && len < dstsize)
		len++;
	i = len;
	while (src[len - i] != 0 && (len + 1 < dstsize))
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < dstsize)
		dst[len] = 0;
	return (i + ft_strlen(src));
}
