/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:02:56 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 22:03:43 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_handler.h"

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

void	rotate_right(t_game *game)
{
	double	old;
	double	cos_rot;
	double	sin_rot;

	old = game->player_direction_x;
	cos_rot = cos(-game->rot_speed);
	sin_rot = sin(-game->rot_speed);
	game->player_direction_x = game->player_direction_x * cos_rot
		- game->player_direction_y * sin_rot;
	game->player_direction_y = old * sin_rot
		+ game->player_direction_y * cos_rot;
	old = game->plane_x;
	game->plane_x = game->plane_x * cos_rot - game->plane_y * sin_rot;
	game->plane_y = old * sin_rot + game->plane_y * cos_rot;
}

void	rotate_left(t_game *game)
{
	double	old;
	double	cos_rot;
	double	sin_rot;

	old = game->player_direction_x;
	cos_rot = cos(game->rot_speed);
	sin_rot = sin(game->rot_speed);
	game->player_direction_x = game->player_direction_x * cos_rot
		- game->player_direction_y * sin_rot;
	game->player_direction_y = old * sin_rot
		+ game->player_direction_y * cos_rot;
	old = game->plane_x;
	game->plane_x = game->plane_x * cos_rot - game->plane_y * sin_rot;
	game->plane_y = old * sin_rot + game->plane_y * cos_rot;
}

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == key_esc)
		exit(0);
	if (keycode == key_arrow_up)
		forward(game);
	if (keycode == key_arrow_down)
		backwards(game);
	if (keycode == key_arrow_right)
		rotate_right(game);
	if (keycode == key_arrow_left)
		rotate_left(game);
	redraw(game);
	return (0);
}
