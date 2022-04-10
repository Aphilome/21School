/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:39:42 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 13:39:56 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen(char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != 0)
		i++;
	return (i);
}

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

// индекс, на котором строки начали отличаться. -1 если не одинаковые
int	start_with(char *str, char *sub_str)
{
	int	i;

	i = 0;
	if (str == NULL || sub_str == NULL || ft_strlen(str) < ft_strlen(sub_str))
		return (-1);
	while (sub_str[i] != 0 && str[i] == sub_str[i])
		i++;
	if (sub_str[i] != 0)
		return (-1);
	return (i);
}

int	ft_simple_atoi(char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}
