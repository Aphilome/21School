#include "mlx_adapter/mlx_adapter.h"
#include "parser/parser.h"
#include "loader/game_loader.h"
#include "raycasting_logic/raycasting_logic.h"
#include "key_handler/key_handler.h"

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
	return (0);
}
