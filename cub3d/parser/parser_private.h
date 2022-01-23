#ifndef CUB3D_PARSER_PRIVATE_H
#define CUB3D_PARSER_PRIVATE_H

#include <sys/fcntl.h>
#include "parser.h"

void 	no_settings_setter(t_map *map, char *value);
void 	so_settings_setter(t_map *map, char *value);
void 	we_settings_setter(t_map *map, char *value);
void 	ea_settings_setter(t_map *map, char *value);

t_list *read_all_file(char *file_name);

t_bool	is_settings_info_line(char *str);
t_bool	is_map_info_line(char *str);
t_bool	is_empty_line(char *str);


#endif
