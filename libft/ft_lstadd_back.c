/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:35:29 by aphilome          #+#    #+#             */
/*   Updated: 2021/04/23 22:25:58 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (lst == 0)
		return ;
	p = *lst;
	if (p == NULL)
		(*lst) = new;
	else
	{
		while (p->next != 0)
			p = p->next;
		p->next = new;
	}
}
