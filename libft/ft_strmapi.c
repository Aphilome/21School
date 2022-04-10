/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:45:01 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/21 16:47:01 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*mv;
	size_t			len;
	unsigned int	i;

	i = 0;
	if (str != NULL)
	{
		len = ft_strlen(str);
		mv = malloc(sizeof(char) * (len + 1));
		if (mv == NULL)
			return (NULL);
		while (i < len)
		{
			mv[i] = f(i, str[i]);
			i++;
		}
		mv[i] = 0;
		i++;
		return (mv);
	}
	return (NULL);
}
