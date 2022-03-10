/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:33:38 by tbirdper          #+#    #+#             */
/*   Updated: 2022/02/27 14:34:55 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loader_private.h"

t_game	*game_loader(t_mlx *mlx, t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		error_exit(ERROR_MALLOC);
	game->mlx = mlx;
	game->map = map;
	game->player_pos_x = map->player_start_pos_x;
	game->player_pos_y = map->player_start_pos_y;
	game->player_direction_x = map->player_start_direction_x;
	game->player_direction_y = map->player_start_direction_y;
	game->move_speed = MOVE_SPEED;
	game->rot_speed = ROTATION_SPEED;
	game->plane_y = 0.0;
	game->plane_x = 0.0;
	game->mouse_old_x = 0;
	game->mouse_old_y = 0;
	if (game->player_direction_y == 0)
		game->plane_y += 0.66 * game->player_direction_x * -1;
	if (game->player_direction_x == 0)
		game->plane_x += 0.66 * game->player_direction_y;
	textures_load(game);
	colors_load(game);
	return (game);
}
