#ifndef CUB3D_UTILS_H
#define CUB3D_UTILS_H

#include <unistd.h>
#include <stdlib.h>

#define PROJECT_NAME		"Raycaster"

#define ERROR_SYSTEM		"System"
#define ERROR_MALLOC		"Memory allocation"
#define ERROR_MAP		"Map parsing"
#define ERROR_MAP_SIZE	"Map size"
#define ERROR_ARGC		"Arguments count"
#define ERROR_SETTINGS	"Settings parse error"
#define ERROR_UNDEFINED	"Undefined settings error"
#define ERROR_MLX		"MLX creating"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef enum e_ColorRGB // DEL
{
	RGB_Red,
	RGB_Green,
	RGB_Blue,
	RGB_White,
	RGB_Yellow
} ColorRGB;

typedef struct s_mlx
{
	void *mlx;
	void *window;
	void *image;
}	t_mlx;

typedef enum e_map_cell
{
	cell_empty = 0,
	cell_wall = 1,
	cell_space = 100
} t_map_cell;

typedef struct s_map
{
	char *north_texture_path;
	char *south_texture_path;
	char *west_texture_path;
	char *east_texture_path;

	int floor_color[3];
	int ceiling_color[3];

	int map_width;
	int map_height;
	t_map_cell **map;
}	t_map;

int		ft_strlen(char *msg);
void	error_exit(char *msg);
void	print_strl(char *msg);
void	print_str(char *msg);
int		start_with(char *str, char *sub_str);
char	*trim(char *str);
char	*ft_strdup(char *src);
int		ft_simple_atoi(char *str);
void	print_nbr(int n);
void	print_nbrl(int n);

#endif
