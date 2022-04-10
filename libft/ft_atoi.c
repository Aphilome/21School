/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:46:14 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 21:35:04 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	is_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign_change;
	int	res;

	sign_change = 1;
	i = is_space(str);
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (*(str + i) == '-')
		{
			sign_change = -sign_change;
			i++;
		}
		else
			i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + *(str + i) - '0';
		i++;
	}
	return (res * sign_change);
}
