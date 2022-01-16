/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:41 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/07 18:25:56 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

size_t	array_len(char **s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

size_t	fill_array(char **mas, char **s, size_t start)
{
	size_t	i;

	if (s == NULL)
		return (start);
	i = 0;
	while (s[i] != NULL)
	{
		mas[start + i] = s[i];
		i++;
	}
	return (start + i);
}
