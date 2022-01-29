#ifndef CUB3D_UTILS_H
#define CUB3D_UTILS_H

#include <unistd.h>
#include <stdlib.h>

#define ERROR_SYSTEM "System"
#define ERROR_MALLOC "Memory allocation"
#define ERROR_MAP "Map parsing"
#define ERROR_ARGC "Arguments count"
#define ERROR_SETTINGS "Settings parse error"
#define ERROR_UNDEFINED "Undefined settings error"

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

	int floor_color[3];
	int ceiling_color[3];

	char **map;
	int map_lines;
}	t_map;


int ft_strlen(char *msg);
void error_exit(char *msg);
void print_strl(char *msg);
void print_str(char *msg);
int start_with(char *str, char *sub_str);
char	*trim(char *str);
char	*ft_strdup(char *src);
int	ft_simple_atoi(char *str);

#endif
