/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:39:23 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 13:39:30 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_strl(char *msg)
{
	print_str(msg);
	print_str("\n");
}

void	print_nbrl(int n)
{
	print_nbr(n);
	print_str("\n");
}

void	print_nbr(int n)
{
	char	mod;

	if (n < 0)
	{
		write(1, "-", 1);
		mod = (char)((0 - n % 10) + '0');
		if (0 - (n / 10) > 0)
			print_nbr(0 - (n / 10));
		write(1, &mod, 1);
		return ;
	}
	mod = (char)(n % 10 + '0');
	if (n / 10 > 0)
		print_nbr(n / 10);
	write(1, &mod, 1);
}

void	print_str(char *msg)
{
	write(1, msg, ft_strlen(msg));
}
