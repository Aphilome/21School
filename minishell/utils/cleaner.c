/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:27:52 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 17:11:21 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	try_free(void *s)
{
	if (s != NULL)
		free(s);
}

void	try_free2(void *s1, void *s2)
{
	try_free(s1);
	try_free(s2);
}

void	try_free3(void *s1, void *s2, void *s3)
{
	try_free(s1);
	try_free(s2);
	try_free(s3);
}

void	try_free4(void *s1, void *s2, void *s3, void *s4)
{
	try_free(s1);
	try_free(s2);
	try_free(s3);
	try_free(s4);
}
