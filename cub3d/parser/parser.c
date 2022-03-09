/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:30:33 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/29 22:47:18 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

t_map	*get_empty_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		error_exit(ERROR_MALLOC);
	map->map = NULL;
	map->east_texture_path = NULL;
	map->north_texture_path = NULL;
	map->west_texture_path = NULL;
	map->south_texture_path = NULL;
	map->ceiling_color[0] = -1;
	map->ceiling_color[1] = -1;
	map->ceiling_color[2] = -1;
	map->floor_color[0] = -1;
	map->floor_color[1] = -1;
	map->floor_color[2] = -1;
	map->map_width = 0;
	map->map_height = 0;
	map->player_start_pos_x = -1;
	map->player_start_pos_y = -1;
	return (map);
}

void	parse_settings(t_map *map, char *str)
{
	if (settings_setter(str, map, "NO", no_settings_setter)
		|| settings_setter(str, map, "SO", so_settings_setter)
		|| settings_setter(str, map, "WE", we_settings_setter)
		|| settings_setter(str, map, "EA", ea_settings_setter)
		|| settings_setter(str, map, "F", f_settings_setter)
		|| settings_setter(str, map, "C", c_settings_setter)
		|| undefined_settings())
		;
}

t_map	*map_parser(char *file_name)
{
	t_list	*head;
	t_list	*map_start;
	t_map	*map;

	map = get_empty_map();
	head = read_all_file(file_name);
	if (ft_lstsize(head) < 9)
		error_exit(ERROR_MAP);
	map_start = init_settings(head, map);
	map_init(map, map_start);
	ft_lstclear(&head, string_cleaner);
	return (map);
}
