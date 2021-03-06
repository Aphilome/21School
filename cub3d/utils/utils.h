/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:40:02 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/10 17:35:49 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "../list/list.h"

# define PROJECT_NAME		"Raycaster"
# define MOVE_SPEED			0.2
# define ROTATION_SPEED		0.015
# define TEXTURE_WIDTH		64
# define TEXTURE_HEIGHT		64
# define VALIDATOR_OFFSET	100000
# define SCREEN_WIDTH		640
# define SCREEN_HEIGHT		480

# define ERROR_SYSTEM		"System"
# define ERROR_MALLOC		"Memory allocation"
# define ERROR_MAP			"Map parsing"
# define ERROR_MAP_SIZE		"Map size"
# define ERROR_ARGC			"Arguments count"
# define ERROR_SETTINGS		"Settings parse error"
# define ERROR_OPEN_FILE	"Open XMP file"
# define ERROR_SIZE_FILE	"File need be 64x64 px"
# define ERROR_PIXEL_FILE	"px must: bitsPerPixel 32; sizeLine 256; endian 0"
# define ERROR_UNDEFINED	"Undefined settings error"
# define ERROR_MLX			"MLX creating"
# define ERROR_TWO_PLAYER	"Detected two player"
# define ERROR_NO_SET_MAP	"Some parameters not set"
# define ERROR_NO_FILE		"Not found file"

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
	void	*mlx;
	void	*window;
	void	*image;
	int		bytes_per_pixel;
	int		line_length;
	char	*mlx_addr;
}	t_mlx;

typedef enum e_map_cell
{
	cell_empty = 0,
	cell_wall = 1,
	cell_space = 100
}	t_map_cell;

typedef struct s_map
{
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;

	int			floor_color[3];
	int			ceiling_color[3];

	int			map_width;
	int			map_height;

	double		player_start_pos_x;
	double		player_start_pos_y;

	double		player_start_direction_x;
	double		player_start_direction_y;

	t_map_cell	**map;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
	char	*textures[4];

	int		floor_color;
	int		ceiling_color;

	int		mouse_old_x;
	int		mouse_old_y;

	double	player_pos_x;
	double	player_pos_y;

	double	player_direction_x;
	double	player_direction_y;

	double	plane_x;
	double	plane_y;

	double	move_speed;
	double	rot_speed;
}	t_game;

typedef enum e_key_code
{
	key_a = 0,
	key_s = 1,
	key_d = 2,
	key_scroll_down = 4,
	key_scroll_up = 5,
	key_w = 13,
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
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif
