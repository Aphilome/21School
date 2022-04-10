/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:03:24 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/17 21:03:25 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src_buf, int a, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		((char *)src_buf)[i++] = (char)a;
	return (src_buf);
}
