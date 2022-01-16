/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:23:12 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:23:13 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putchar_fd(char c, int fd)
{
	if (errno == 0 && fd == STDERR_FILENO)
	{
		write(fd, &c, 1);
		errno = 0;
	}
	else
		write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != 0)
		ft_putchar_fd(s[i++], fd);
}

void	ft_print_error(const char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
}

void	ft_print_str(const char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
}
