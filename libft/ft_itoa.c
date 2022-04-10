/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 23:05:02 by aphilome          #+#    #+#             */
/*   Updated: 2021/07/11 16:39:33 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_way (long long sign_n)
{
	int	i;

	i = 0;
	if (sign_n < 0)
	{
		sign_n = sign_n * (-1);
		i++;
	}
	while (sign_n > 0)
	{
		sign_n = sign_n / 10;
		i++;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	t;

	i = 0;
	length = 0;
	while (str[length])
		length++;
	length--;
	while (i < length)
	{
		t = str[i];
		str[i] = str[length];
		str[length] = t;
		length--;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long long	long_n;
	char		*string;
	int			i;

	long_n = n;
	if (long_n == 0)
		return (ft_strdup("0"));
	string = malloc(sizeof(char) * ft_way(long_n) + 1);
	i = 0;
	if (string == NULL)
		return (NULL);
	if (long_n < 0)
		long_n = -long_n;
	while (long_n != 0)
	{
		string[i] = (long_n % 10) + '0';
		i++;
		long_n = long_n / 10;
	}
	if (n < 0)
		string[i++] = '-';
	string[i] = 0;
	return (ft_strrev(string));
}
