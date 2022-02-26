#include "game_loader_private.h"

char *load_texture(t_mlx *mlx, char *filepath)
{
	int width;
	int height;

	void *tex_img = mlx_xpm_file_to_image(mlx->mlx, filepath,
										  &width, &height);
	if (tex_img == NULL)
		error_exit(ERROR_OPEN_FILE);
	if (width != TEXTURE_WIDTH || height != TEXTURE_HEIGHT)
		error_exit(ERROR_SIZE_FILE);

	int bpp;
	int sl;
	int e;
	char *tex_ptr = mlx_get_data_addr(tex_img, &bpp, &sl, &e);

	if (bpp != 32 || sl != 256 || e != 0)
		error_exit(ERROR_PIXEL_FILE);
	return tex_ptr;
}

t_game *game_loader(t_mlx *mlx, t_map *map)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		error_exit(ERROR_MALLOC);
	game->mlx = mlx;
	game->map = map;
	game->player_pos_x = map->player_start_pos_x;
	game->player_pos_y = map->player_start_pos_y;
	game->player_direction_x = map->player_start_direction_x;
	game->player_direction_y = map->player_start_direction_y;
	game->plane_y = 0.0;
	game->plane_x = 0.0;
	if (game->player_direction_y == 0)
		game->plane_y += 0.66 * game->player_direction_x * -1;
	if (game->player_direction_x == 0)
		game->plane_x += 0.66 * game->player_direction_y;

	game->moveSpeed = MOVE_SPEED;
	game->rotSpeed = ROTATION_SPEED;




	game->textures[cd_north] = load_texture(mlx, game->map->north_texture_path);
	game->textures[cd_east] = load_texture(mlx, game->map->east_texture_path);
	game->textures[cd_south] = load_texture(mlx, game->map->south_texture_path);
	game->textures[cd_west] = load_texture(mlx, game->map->west_texture_path);




	return game;
}