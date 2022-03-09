/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:33:06 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 13:33:31 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

void	set_player_position(t_map *map, int row, int col, char cd)
{
	map->map[row][col] = cell_empty;
	if (!(map->player_start_pos_x == -1 && map->player_start_pos_y == -1))
		error_exit(ERROR_TWO_PLAYER);
	map->player_start_pos_x = row + 1 / 1e10 + 0.5;
	map->player_start_pos_y = col + 1 / 1e10 + 0.5;
	if (cd == 'N')
	{
		map->player_start_direction_x = -1;
		map->player_start_direction_y = 0;
	}
	else if (cd == 'S')
	{
		map->player_start_direction_x = 1;
		map->player_start_direction_y = 0;
	}
	else if (cd == 'W')
	{
		map->player_start_direction_x = 0;
		map->player_start_direction_y = -1;
	}
	else if (cd == 'E')
	{
		map->player_start_direction_x = 0;
		map->player_start_direction_y = 1;
	}
}

void	row_filler(t_map *map, int row, char *line)
{
	int	i;

	i = 0;
	while (i < map->map_width && line[i] != 0)
	{
		if (line[i] == ' ')
			map->map[row][i] = cell_space;
		else if (line[i] == '0')
			map->map[row][i] = cell_empty;
		else if (line[i] == '1')
			map->map[row][i] = cell_wall;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W')
			set_player_position(map, row, i, line[i]);
		i++;
	}
	while (i < map->map_width)
		map->map[row][i++] = cell_space;
}

void	map_creator(t_map *map, t_list *head)
{
	int	i;

	if (map->map_width < 3 || map->map_height < 3)
		error_exit(ERROR_MAP_SIZE);
	map->map = malloc(sizeof(t_map_cell *) * map->map_height);
	if (map->map == NULL)
		error_exit(ERROR_MALLOC);
	i = 0;
	while (i < map->map_height)
	{
		map->map[i] = malloc(sizeof(t_map_cell) * map->map_width);
		if (map->map[i] == NULL)
			error_exit(ERROR_MALLOC);
		row_filler(map, i, head->content);
		head = head->next;
		i++;
	}
}

void	map_init(t_map *map, t_list *head)
{
	map_creator(map, head);
	map_validator(map);
}
