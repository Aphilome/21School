/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:30:33 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/28 22:38:31 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

void	print_file(t_list *head)
{
	print_strl("=======================");
	while (head != NULL)
	{
		print_strl(head->content);
		head = head->next;
	}
	print_strl("=======================");
}

void	print_map(t_map *map)
{
	print_strl("#######################");
	if (map == NULL)
		print_strl("map NULL");
	if (map->north_texture_path == NULL)
		print_strl("map north_texture_path NULL");
	print_str("NO: ");
	print_strl(map->north_texture_path);
	print_str("SO: ");
	print_strl(map->south_texture_path);
	print_str("WE: ");
	print_strl(map->west_texture_path);
	print_str("EA: ");
	print_strl(map->east_texture_path);
	// F
	// C
	// map
	print_strl("#######################");
}

t_map	*get_empty_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		error_exit(ERROR_MALLOC);
	map->map = NULL;
	map->map_lines = 0;
	map->east_texture_path = NULL;
	map->north_texture_path = NULL;
	map->west_texture_path = NULL;
	map->south_texture_path = NULL;
	map->ceiling_color[0] = 0;
	map->ceiling_color[1] = 0;
	map->ceiling_color[2] = 0;
	map->floor_color[0] = 0;
	map->floor_color[1] = 0;
	map->floor_color[2] = 0;
	return (map);
}

void	parse_settings(t_map *map, char *str)
{
	if (settings_setter(str, map, "NO", no_settings_setter)
		|| settings_setter(str, map, "SO", so_settings_setter)
		|| settings_setter(str, map, "WE", we_settings_setter)
		|| settings_setter(str, map, "EA", ea_settings_setter)
		|| undefined_settings();)
		;
}

t_map	*map_parser(char *file_name)
{
	t_list	*head;
	t_list	*map_start;
	t_map	*map;

	map = get_empty_map();
	head = read_all_file(file_name);
	print_file(head);
	if (ft_lstsize(head) < 9)
		error_exit(ERROR_MAP);
	map_start = init_settings(head, map);
	print_map(map);
	return (map);
}
