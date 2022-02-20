#ifndef CUB3D_UTILS_H
#define CUB3D_UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include "../list/list.h"

#define PROJECT_NAME		"Raycaster"
#define MOVE_SPEED		0.8
#define ROTATION_SPEED	0.2
#define TEXTURE_WIDTH	64
#define TEXTURE_HEIGHT	64
#define TEXTURE_SIZE		TEXTURE_WIDTH * TEXTURE_HEIGHT

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

typedef enum e_cardinal_directions
{
	cd_west = 0,
	cd_north = 1,
	cd_east = 2,
	cd_south = 3
}	t_cardinal_directions;

typedef struct s_mlx
{
	void *mlx;
	void *window;
	void *image;
	int bytes_per_pixel;
	int line_length;
	char *mlx_addr;
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

	double player_start_pos_x;
	double player_start_pos_y;

	double player_start_direction_x;
	double player_start_direction_y;

	unsigned int textures[4][TEXTURE_SIZE];

	t_map_cell **map;
}	t_map;



typedef struct s_game
{
	t_map		*map;
	t_mlx		*mlx;

	double player_pos_x;
	double player_pos_y;

	double  player_direction_x;
	double  player_direction_y;

	double plane_x;
	double plane_y;

	double moveSpeed;
	double rotSpeed;

	double time;
	double oldTime;
}	t_game;

typedef enum e_key_code
{
	key_scroll_down = 4,
	key_scroll_up = 5,
	key_esc = 53,
	key_plus = 69,
	key_minus = 78,
	key_arrow_left = 123,
	key_arrow_right = 124,
	key_arrow_down = 125,
	key_arrow_up = 126,
}	t_key_code;

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
