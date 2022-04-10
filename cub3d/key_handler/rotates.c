/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:45:10 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 22:45:24 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_handler_private.h"

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
