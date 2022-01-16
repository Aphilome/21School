/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:25:51 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:43:14 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*str_get_word(char *s)
{
	size_t	i;
	size_t	j;

	if (is_empty(s))
		return (s);
	i = 0;
	while (is_space(s[i]) && s[i] != NT_SPACE)
		i++;
	if (s[i] == 0)
		return (NULL);
	j = i;
	while ((s[j] == NT_SPACE || is_space(s[j]) == false) && s[j] != 0)
		j++;
	return (ft_substr(s, i, j - i));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		diff;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

t_bool	ft_str_is_alpha(char c)
{
	if (c < 'A' || c > 'Z')
	{
		if (c < 'a' || c > 'z')
			return (false);
	}
	return (true);
}

t_bool	ft_str_is_num(char c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}

void	remove_nt_space(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == NT_SPACE)
			s[i] = ' ';
		i++;
	}
}
