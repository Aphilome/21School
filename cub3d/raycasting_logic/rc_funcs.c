/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:51:37 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 16:09:58 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_logic_private.h"

void	dda(t_game *game, t_ray_casting *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (game->map->map[rc->map_x][rc->map_y] == cell_wall)
			hit = 1;
	}
}

t_cardinal_directions	get_cd(t_game *game, t_ray_casting *rc)
{
	t_cardinal_directions	cd;

	cd = rc->side;
	if (game->player_pos_y >= rc->map_y && game->player_pos_x >= rc->map_x)
		cd = -(rc->side - 3);
	if (game->player_pos_y <= rc->map_y && game->player_pos_x >= rc->map_x)
		cd = (rc->side - 1) * -3;
	if (game->player_pos_y <= rc->map_y && game->player_pos_x <= rc->map_x)
		cd = -(rc->side - 1);
	if (game->player_pos_y >= rc->map_y && game->player_pos_x <= rc->map_x)
		cd = rc->side + 1;
	return (cd);
}

void	calc_step_and_side(t_game *game, t_ray_casting *rc)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (game->player_pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - game->player_pos_x)
			* rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (game->player_pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - game->player_pos_y)
			* rc->delta_dist_y;
	}
}

void	calc_tex_params(t_game *game, t_ray_casting *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->side_dist_x - rc->delta_dist_x);
	else
		rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
	rc->line_height = (int)(rc->h / rc->perp_wall_dist);
	rc->pitch = 100;
	rc->draw_start = ft_max(0, -rc->line_height / 2 + rc->h / 2 + rc->pitch);
	rc->draw_end = ft_min(rc->h - 1, rc->line_height / 2 + rc->h / 2
			+ rc->pitch);
	rc->cd = get_cd(game, rc);
	if (rc->side == 0)
		rc->wall_x = game->player_pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wall_x = game->player_pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wall_x -= floor(rc->wall_x);
	rc->tex_x = (int)(rc->wall_x * (double)TEXTURE_WIDTH);
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
	if (rc->side == 1 && rc->ray_dir_y < 0)
		rc->tex_x = TEXTURE_WIDTH - rc->tex_x - 1;
}
