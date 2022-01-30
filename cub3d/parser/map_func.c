#include "parser_private.h"

void	row_filler(t_map *map, int row, char *line)
{
	int i;

	i = 0;
	while (i < map->map_width && line[i] != 0)
	{
		if (line[i] == ' ')
			map->map[row][i] = cell_space;
		else if (line[i] == '0')
			map->map[row][i] = cell_empty;
		else if (line[i] == '1')
			map->map[row][i] = cell_wall;
		i++;
	}
	while (i < map->map_width)
		map->map[row][i++] = cell_space;
}

void map_creator(t_map *map, t_list *head)
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
	// validator

}