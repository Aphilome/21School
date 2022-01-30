#include "parser_private.h"

t_map_cell	**map_creator(int width, int height)
{
	t_map_cell	**map;

	(void)map;
	if (width < 3 || height < 3)
		error_exit(ERROR_MAP_SIZE);
	map = malloc(sizeof(t_map_cell *) * height);

	return (NULL);
}
