/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:22:56 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:30:05 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}

size_t	get_numlen(ssize_t sign_n)
{
	size_t	count;

	count = 0;
	if (sign_n < 0)
	{
		sign_n = -sign_n;
		count++;
	}
	while (sign_n > 0)
	{
		sign_n = sign_n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(ssize_t n)
{
	ssize_t	long_n;
	char	*string;
	size_t	char_count;

	if (n == 0)
		return (ft_strdup("0"));
	char_count = get_numlen(n);
	string = malloc(sizeof(char) * (char_count + 1));
	is_system_error();
	long_n = n;
	if (long_n < 0)
		long_n = -long_n;
	string[char_count--] = 0;
	while (long_n != 0)
	{
		string[char_count--] = (char)((long_n % 10) + '0');
		long_n = long_n / 10;
	}
	if (n < 0)
		string[0] = '-';
	return (string);
}
