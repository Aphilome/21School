/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:44:59 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 22:45:06 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_handler_private.h"

void	forward(t_game *game)
{
	double	step;
	int		x;
	int		y;

	step = game->player_direction_x * game->move_speed;
	x = (int)(game->player_pos_x + step);
	y = (int)game->player_pos_y;
	if (game->map->map[x][y] == cell_empty)
		game->player_pos_x += step;
	step = game->player_direction_y * game->move_speed;
	x = (int)(game->player_pos_x);
	y = (int)(game->player_pos_y + step);
	if (game->map->map[x][y] == cell_empty)
		game->player_pos_y += step;
}

void	backwards(t_game *game)
{
	double	step;
	int		x;
	int		y;

	step = game->player_direction_x * game->move_speed;
	x = (int)(game->player_pos_x - step);
	y = (int)(game->player_pos_y);
	if (game->map->map[x][y] == cell_empty)
		game->player_pos_x -= step;
	step = game->player_direction_y * game->move_speed;
	x = (int)(game->player_pos_x);
	y = (int)(game->player_pos_y - step);
	if (game->map->map[x][y] == cell_empty)
		game->player_pos_y -= step;
}

void	left(t_game *game)
{
	double	old;

	old = game->rot_speed;
	game->rot_speed = 1.572;
	rotate_left(game);
	forward(game);
	rotate_right(game);
	game->rot_speed = old;
}

void	right(t_game *game)
{
	double	old;

	old = game->rot_speed;
	game->rot_speed = 1.572;
	rotate_right(game);
	forward(game);
	rotate_left(game);
	game->rot_speed = old;
}
