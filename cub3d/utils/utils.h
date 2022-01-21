#ifndef CUB3D_UTILS_H
#define CUB3D_UTILS_H

#include <unistd.h>
#include <stdlib.h>

#define ERROR_SYSTEM "System"
#define ERROR_MALLOC "Memory allocation"
#define ERROR_MAP "Map parsing"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_map
{
	char *north_texture_path;
	char *south_texture_path;
	char *west_texture_path;
	char *east_texture_path;

	char floor_color[3];
	char ceiling_color[3];

	char **map;
	int map_lines;
}	t_map;


int ft_strlen(char *msg);
void error_exit(char *msg);
void print_str(char *msg);

#endif
