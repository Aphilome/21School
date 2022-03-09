/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:05:38 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 22:06:38 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_adapter/mlx_adapter.h"
#include "parser/parser.h"
#include "loader/game_loader.h"
#include "raycasting_logic/raycasting_logic.h"
#include "key_handler/key_handler.h"

int	close_app(void *p)
{
	(void)p;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		error_exit(ERROR_ARGC);
	mlx = mlx_adapter_init(SCREEN_WIDTH, SCREEN_HEIGHT);
	map = map_parser(argv[1]);
	game = game_loader(mlx, map);
	redraw(game);
	mlx_key_hook(mlx->window, key_handler, game);
	mlx_hook(mlx->window, 17, 0, close_app, NULL);
	mlx_loop(mlx);
	return (0);
}
