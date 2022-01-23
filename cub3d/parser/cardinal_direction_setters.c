#include "parser_private.h"

void 	no_settings_setter(t_map *map, char *value)
{
	map->north_texture_path = value;
}

void 	so_settings_setter(t_map *map, char *value)
{
	map->south_texture_path = value;
}

void 	we_settings_setter(t_map *map, char *value)
{
	map->west_texture_path = value;
}

void 	ea_settings_setter(t_map *map, char *value)
{
	map->east_texture_path = value;
}

t_bool	undefined_settings(void)
{
	error_exit(ERROR_UNDEFINED);
	return (true);
}
