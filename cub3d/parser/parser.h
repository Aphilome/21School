#ifndef CUB3D_PARSER_H
#define CUB3D_PARSER_H

#include "../utils/utils.h"
#include "../get_next_line/get_next_line.h"
#include "../list/list.h"

char **map_parser_tmp(char *file_name);

t_map *map_parser(char *file_name);

#endif
