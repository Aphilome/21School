#include "parser_private.h"

void	f_settings_setter(t_map *map, char *value)
{
	(void)value;
	map->floor_color[0] = 0;
}

void	c_settings_setter(t_map *map, char *value)
{
	(void)value;
	map->ceiling_color[0] = 0;
}