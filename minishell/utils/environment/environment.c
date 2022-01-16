/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:28:06 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 16:05:58 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void		ft_env_lstadd_back(t_env_list **root, t_env_list *new);
t_env_list	*ft_env_lstnew(char *value, t_bool is_hidden);
char		*env_adapter(char *env, t_bool *is_hidden);
void		concat_env(t_env_list *p, char *input, size_t i);
void		create_and_add_env(char *input, t_bool is_hidden, char *key,
				t_env_list **env);

t_env_list	*create_environment(char **env)
{
	size_t		i;
	t_env_list	*tmp;
	t_env_list	*root;
	t_bool		is_hidden;
	char		*adapter;

	if (ft_arr_strlen(env) == 0)
		return (NULL);
	i = 0;
	adapter = env_adapter(env[i++], &is_hidden);
	root = ft_env_lstnew(adapter, is_hidden);
	while (env[i] != NULL)
	{
		adapter = env_adapter(env[i++], &is_hidden);
		tmp = ft_env_lstnew(adapter, is_hidden);
		ft_env_lstadd_back(&root, tmp);
	}
	return (root);
}

void	del_env(char *key, t_env_list **env)
{
	t_env_list	*pp;
	t_env_list	*p;

	pp = NULL;
	p = *env;
	while (p != NULL)
	{
		if (ft_start_with(p->value, key, false)
			&& p->value[ft_strlen(key)] == '=')
		{
			if (p == *env)
				*env = p->next;
			else
				pp->next = p->next;
			try_free2(p->value, p);
			return ;
		}
		pp = p;
		p = p->next;
	}
}

char	*get_env_key(char *input, t_bool is_hidden, t_bool is_concat, size_t *i)
{
	char		*key;

	key = NULL;
	if (is_hidden)
		key = str_get_word(input);
	else
	{
		*i = ft_strlen_to_char(input, '=');
		if (is_concat)
		{
			key = ft_substr(input, 0, *i);
			key[*i - 1] = '=';
		}
		else
			key = ft_substr(input, 0, *i + 1);
	}
	return (key);
}

void	add_new_env(char *input, t_env_list **env, t_bool is_concat,
			t_bool is_hidden)
{
	t_env_list	*p;
	char		*key;
	size_t		i;

	key = get_env_key(input, is_hidden, is_concat, &i);
	p = *env;
	while (p != NULL)
	{
		if (ft_start_with(p->value, key, false))
		{
			try_free(key);
			if (is_hidden)
				return ;
			if (is_concat)
			{
				concat_env(p, input, i);
				return ;
			}
			try_free(p->value);
			p->value = ft_strdup(input);
			return ;
		}
		p = p->next;
	}
	create_and_add_env(input, is_hidden, key, env);
}
