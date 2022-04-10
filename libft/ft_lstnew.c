/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:28:45 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/22 01:28:56 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*st;

	st = malloc(sizeof(t_list));
	if (st == NULL)
		return (NULL);
	st->content = content;
	st->next = NULL;
	return (st);
}
