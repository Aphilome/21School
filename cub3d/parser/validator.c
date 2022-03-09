#include "parser_private.h"

void base_validator(t_map *map)
{
	if (map->east_texture_path == NULL
	|| map->north_texture_path == NULL
	|| map->west_texture_path == NULL
	|| map->south_texture_path == NULL)
		error_exit(ERROR_NO_SET_MAP);
	if (map->ceiling_color[0] == -1
	|| map->ceiling_color[1] == -1
	|| map->ceiling_color[2] == -1
	|| map->floor_color[0] == -1
	|| map->floor_color[1] == -1
	|| map->floor_color[2] == -1)
		error_exit(ERROR_NO_SET_MAP);
	if (map->map_width == 0
	|| map->map_height == 0
	|| map->player_start_pos_x == -1
	|| map->player_start_pos_y == -1
	|| map->map == NULL )
		error_exit(ERROR_NO_SET_MAP);
}

t_bool get_empty_cell_coord(t_map *map, int *out_i, int *out_j)
{
	*out_i = 0;
	while (*out_i < map->map_height)
	{
		*out_j = 0;
		while (*out_j < map->map_width)
		{
			if (map->map[*out_i][*out_j] == cell_empty)
				return (true);
			(*out_j)++;
		}
		(*out_i)++;
	}
	return (false);
}

void path_validator(t_map *map, int s_i, int s_j)
{
	if (s_i < 0 || s_j < 0 || s_i >= map->map_height || s_j >= map->map_width
		|| map->map[s_i][s_j] == cell_space)
		error_exit(ERROR_MAP);
	else if (map->map[s_i][s_j] == cell_empty)
	{
		map->map[s_i][s_j] += VALIDATOR_OFFSET;
		path_validator(map, s_i - 1, s_j);
		path_validator(map, s_i, s_j + 1);
		path_validator(map, s_i + 1, s_j);
		path_validator(map, s_i, s_j - 1);
	}
}

void path_normalizer(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map[i][j] == cell_empty + VALIDATOR_OFFSET)
				map->map[i][j] -= VALIDATOR_OFFSET;
			j++;
		}
		i++;
	}
}

void map_validator(t_map *map)
{
	int i;
	int j;

	base_validator(map);
	if (get_empty_cell_coord(map, &i, &j) == false)
		error_exit(ERROR_MAP);
	path_validator(map, i, j);
	while (get_empty_cell_coord(map, &i, &j))
		path_validator(map, i, j);
	path_normalizer(map);
}
