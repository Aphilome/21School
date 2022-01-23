#include "parser_private.h"

char *try_get_value(char *key, char *str)
{
	int i;
	char *tmp;
	char *value;

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
	char *value;

	value = try_get_value(key, str);
	if (value != NULL)
	{
		setter(map, value);
		return (true);
	}
	return (false);
}

void map_start_handle(t_list **head, t_list **map_start, t_bool *settings_state)
{
	*settings_state = false;
	*map_start = *head;
	*head = (*head)->next;
}

t_list *init_settings(t_list *head, t_map *map)
{
	t_bool settings_state;
	t_list *map_start;

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
			map_start_handle(&head, &map_start, &settings_state);
		else if (!settings_state && is_map_info_line(head->content))
			head = head->next;
		else if (head->next == NULL && is_empty_line(head->content))
			break;
		else
			error_exit(ERROR_MAP);
	}
	return (map_start);
}