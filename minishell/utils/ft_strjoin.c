/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:22:18 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 19:44:11 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*str2str(char *mv, const char *s)
{
	while (*s != 0)
	{
		*mv = *s;
		mv++;
		s++;
	}
	return (mv);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	char	*base;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	base = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	is_system_error();
	s = base;
	s = str2str(s, s1);
	s = str2str(s, s2);
	*s = 0;
	return (base);
}

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	char	*join2;

	join = NULL;
	join2 = NULL;
	join = ft_strjoin(s1, s2);
	join2 = ft_strjoin(join, s3);
	try_free(join);
	return (join2);
}
