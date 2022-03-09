/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:39:11 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/28 22:40:18 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

char	*try_get_value(char *key, char *str)
{
	int		i;
	char	*tmp;
	char	*value;

	tmp = trim(str);
	if (ft_strlen(tmp) < 4)
		error_exit(ERROR_SETTINGS);
	i = start_with(tmp, key);
	if (i == -1)
	{
		free(tmp);
		return (NULL);
	}
	if (tmp[i] != ' ')
		error_exit(ERROR_SETTINGS);
	while (tmp[i] == ' ')
		i++;
	value = ft_strdup(&(tmp[i]));
	free(tmp);
	return (value);
}

t_bool	settings_setter(char *str, t_map *map, char *key,
						void (*setter)(t_map *, char *))
{
	char	*value;

	value = try_get_value(key, str);
	if (value != NULL)
	{
		setter(map, value);
		free(value);
		return (true);
	}
	return (false);
}

void	map_line_handler(t_list **head, t_map *map)
{
	int width;

	map->map_height++;
	width = ft_strlen((*head)->content);
	if (width > map->map_width)
		map->map_width = width;
	*head = (*head)->next;
}

void	map_start_handle(t_list **head, t_list **map_start,
	t_bool *settings_state, t_map *map)
{
	*settings_state = false;
	*map_start = *head;
	map_line_handler(head, map);
}

t_list	*init_settings(t_list *head, t_map *map)
{
	t_bool	settings_state;
	t_list	*map_start;

	settings_state = true;
	while (head != NULL)
	{
		if (settings_state && is_empty_line(head->content))
			head = head->next;
		else if (settings_state && is_settings_info_line(head->content))
		{
			parse_settings(map, head->content);
			head = head->next;
		}
		else if (settings_state && is_map_info_line(head->content))
			map_start_handle(&head, &map_start, &settings_state, map);
		else if (!settings_state && is_map_info_line(head->content))
			map_line_handler(&head, map);
		else if (head->next == NULL && is_empty_line(head->content))
			break ;
		else
			error_exit(ERROR_MAP);
	}
	return (map_start);
}
