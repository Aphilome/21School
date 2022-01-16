/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:21:06 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:21:08 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

size_t	ft_env_lstsize(t_env_list *lst)
{
	size_t	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_env_lstadd_back(t_env_list **root, t_env_list *new)
{
	t_env_list	*p;

	if (root == NULL)
		return ;
	if (*root == NULL)
	{
		*root = new;
		return ;
	}
	p = *root;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

t_env_list	*ft_env_lstnew(char *value, t_bool is_hidden)
{
	t_env_list	*st;

	st = malloc(sizeof(t_env_list));
	is_system_error();
	st->is_hidden = is_hidden;
	st->value = value;
	st->next = NULL;
	return (st);
}

//void	ft_env_lstclear(t_env_list **lst)
//{
//	t_env_list	*p;
//	t_env_list	*remove;
//
//	if (lst == NULL || *lst == NULL)
//		return ;
//	p = *lst;
//	while (p != NULL)
//	{
//		remove = p;
//		p = p->next;
//		try_free2(remove->value, remove);
//	}
//	*lst = NULL;
//}