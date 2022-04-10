/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 02:05:09 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 23:37:03 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (lst != 0 && del != 0)
	{
		while (*lst != 0)
		{
			p = *lst;
			*lst = p->next;
			(*del)(p->content);
			free(p);
		}
		*lst = NULL;
	}
}
