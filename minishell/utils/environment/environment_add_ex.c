/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_add_ex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:06 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 16:05:31 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

t_env_list	*ft_env_lstnew(char *value, t_bool is_hidden);
void		ft_env_lstadd_back(t_env_list **root, t_env_list *new);

void	concat_env(t_env_list *p, char *input, size_t i)
{
	char		*value;
	char		*tmp;

	value = ft_substr(input, i + 1, ft_strlen(&(input[i])));
	tmp = ft_strjoin(p->value, value);
	try_free2(p->value, value);
	p->value = tmp;
}

void	create_and_add_env(char *input, t_bool is_hidden, char *key,
						   t_env_list **env)
{
	t_env_list	*new;

	if (is_hidden)
		new = ft_env_lstnew(key, true);
	else
	{
		try_free(key);
		new = ft_env_lstnew(ft_strdup(input), false);
	}
	if (*env == NULL)
		*env = new;
	else
		ft_env_lstadd_back(env, new);
}
