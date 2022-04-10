/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:33:10 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/24 00:26:28 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			rmdiv;
	char		c;
	long long	nb_;

	nb_ = n;
	if (nb_ < 0)
	{
		nb_ = -nb_;
		write(fd, "-", 1);
	}
	rmdiv = nb_ % 10;
	if (nb_ / 10 > 0)
		ft_putnbr_fd(nb_ / 10, fd);
	c = rmdiv + '0';
	write(fd, &c, 1);
}
