#include "mlx_adapter/mlx_adapter.h"
#include "parser/parser.h"
#include "loader/game_loader.h"
#include "raycasting_logic/raycasting_logic.h"


int	key_handler(int keycode, void *param)
{
	t_game *game;
	game = (t_game *)param;

	if (keycode == key_esc)
		exit(0);

	//move forward if no wall in front of you
	if(keycode == key_arrow_up)
	{
		if(game->map->map
			[(int)(game->player_pos_x + game->player_direction_x * game->move_speed)]
			[(int)(game->player_pos_y)] == cell_empty)
			game->player_pos_x += game->player_direction_x * game->move_speed;
		if(game->map->map[(int)(game->player_pos_x)][(int)(game->player_pos_y +
				game->player_direction_y * game->move_speed)] == cell_empty)
			game->player_pos_y += game->player_direction_y * game->move_speed;
	}
	//move backwards if no wall behind you
	if(keycode == key_arrow_down)
	{
		if(game->map->map[(int)(game->player_pos_x - game->player_direction_x
		* game->move_speed)][(int)
		(game->player_pos_y)] == cell_empty) game->player_pos_x
		-= game->player_direction_x
				* game->move_speed;
		if(game->map->map[(int)(game->player_pos_x)][(int)(game->player_pos_y
		- game->player_direction_y * game->move_speed)] == cell_empty)
			game->player_pos_y
			-= game->player_direction_y * game->move_speed;
	}
	//rotate to the right
	if(keycode == key_arrow_right)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = game->player_direction_x;
		game->player_direction_x = game->player_direction_x * cos(-
				game->rot_speed) - game->player_direction_y * sin(-game->rot_speed);
		game->player_direction_y = oldDirX * sin(-game->rot_speed) + game->player_direction_y * cos
				(-game->rot_speed);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(-game->rot_speed) - game->plane_y * sin(-game->rot_speed);
		game->plane_y = oldPlaneX * sin(-game->rot_speed) +
				game->plane_y * cos(-game->rot_speed);
	}
	//rotate to the left
	if(keycode == key_arrow_left)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = game->player_direction_x;
		game->player_direction_x = game->player_direction_x * cos(game->rot_speed) - game->player_direction_y * sin(game->rot_speed);
		game->player_direction_y = oldDirX * sin(game->rot_speed) + game->player_direction_y * cos(game->rot_speed);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(game->rot_speed) - game->plane_y * sin(game->rot_speed);
		game->plane_y = oldPlaneX * sin(game->rot_speed) + game->plane_y * cos(game->rot_speed);
	}

	redraw(game);

	return (0);
}


int main(int argc, char **argv)
{
	if (argc != 2)
		error_exit(ERROR_ARGC);
	t_mlx *mlx = mlx_adapter_init(SCREEN_WIDTH, SCREEN_HEIGHT);
	t_map *map = map_parser(argv[1]);
	t_game *game = game_loader(mlx, map);
	redraw(game);
	mlx_key_hook(mlx->window, key_handler, game);
	mlx_loop(mlx);

	return 0;
}
