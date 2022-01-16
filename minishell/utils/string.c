/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:25:51 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 19:38:43 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	scip_spaces(const char *str);
int		get_atoi_sign(const char *str, size_t *i);

t_bool	ft_start_with(const char *input, const char *s, t_bool after_space)
{
	size_t	i;
	size_t	big_len;
	size_t	little_len;

	if (is_empty(input) || is_empty(s))
		return (false);
	big_len = ft_strlen(input);
	little_len = ft_strlen(s);
	if (big_len < little_len)
		return (false);
	i = 0;
	while (s[i] != 0)
	{
		if (input[i] != s[i])
			return (false);
		i++;
	}
	if (!after_space)
		return (true);
	if (input[i] == ' ' || input[i] == '\t' || input[i] == 0)
		return (true);
	return (false);
}

t_bool	is_number_calc(const char *str, size_t i, int sign, long long *res)
{
	if (sign == 1)
	{
		if (*res > *res * 10 + (str[i] - '0'))
			return (false);
		*res = *res * 10 + (str[i] - '0');
	}
	else
	{
		if (*res < *res * 10 - (str[i] - '0'))
			return (false);
		*res = *res * 10 - (str[i] - '0');
	}
	return (true);
}

t_bool	is_number(const char *str)
{
	size_t		i;
	int			sign;
	long long	res;

	i = scip_spaces(str);
	res = 0;
	sign = get_atoi_sign(str, &i);
	while (ft_isdigit(str[i]))
	{
		if (!is_number_calc(str, i, sign, &res))
			return (false);
		i++;
	}
	if (str[i] != 0)
		return (false);
	if (sign == -1 && res > 0 && 0 - res > 0)
		return (false);
	return (true);
}
