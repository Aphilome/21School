/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:29:54 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:30:00 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pwd.h"

void	ft_pwd(void)
{
	char	dir[MAXPATHLEN];

	getcwd(dir, MAXPATHLEN);
	if (errno == ENOENT)
		errno = 0;
	ft_print_str(dir);
	ft_print_str("\n");
}
