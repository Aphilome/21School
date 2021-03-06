/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:02:16 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 21:34:58 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src_buf, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		((char *)src_buf)[i++] = 0;
}
