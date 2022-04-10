/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:37:04 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 21:17:58 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*res;
	size_t		elem_count;
	size_t		i;

	i = 0;
	elem_count = count * size;
	res = malloc(elem_count);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, elem_count);
	return (res);
}
