/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:25:51 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 19:38:59 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	scip_spaces(const char *str);

int	get_atoi_sign(const char *str, size_t *i)
{
	int		sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		res;

	i = scip_spaces(str);
	res = 0;
	sign = get_atoi_sign(str, &i);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

long long	ft_atoll(const char *str)
{
	size_t		i;
	int			sign;
	long long	res;

	i = scip_spaces(str);
	res = 0;
	sign = get_atoi_sign(str, &i);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
