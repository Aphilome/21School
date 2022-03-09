/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:49:59 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 16:09:19 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_logic_private.h"

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)(mlx->mlx_addr
			+ (y * mlx->line_length + x * mlx->bytes_per_pixel));
	*dst = color;
}

int	get_tex_color(t_game *game, t_ray_casting *rc, double *tex_pos,
						double step)
{
	int		tex_y;
	int		color;

	tex_y = (int)*tex_pos & (TEXTURE_HEIGHT - 1);
	*tex_pos += step;
	color = (*(int *)(game->textures[rc->cd]
				+ (4 * TEXTURE_WIDTH * tex_y) + (4 * rc->tex_x)));
	if (rc->side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}

void	vertical_texture_draw(t_game *game, t_ray_casting *rc, int x)
{
	double	step;
	double	tex_pos;
	int		color;
	int		y;

	step = 1.0 * TEXTURE_HEIGHT / rc->line_height;
	tex_pos = (rc->draw_start - rc->pitch - rc->h / 2.0 + rc->line_height / 2.0)
		* step;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y >= rc->draw_start && y < rc->draw_end)
			color = get_tex_color(game, rc, &tex_pos, step);
		else if (y < rc->draw_start)
			color = game->ceiling_color;
		else
			color = game->floor_color;
		put_pixel(game->mlx, x, y++, color);
	}
}

void	set_delta_dist(t_ray_casting *rc)
{
	if (rc->ray_dir_x == 0.0)
		rc->delta_dist_x = 1e30;
	else
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	if (rc->ray_dir_y == 0.0)
		rc->delta_dist_y = 1e30;
	else
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
}

void	redraw(t_game *game)
{
	int				x;
	t_ray_casting	rc;

	x = 0;
	rc.w = SCREEN_WIDTH;
	rc.h = SCREEN_HEIGHT;
	while (x < rc.w)
	{
		rc.camera_x = 2 * x / (double) rc.w - 1;
		rc.ray_dir_x = game->player_direction_x + game->plane_x * rc.camera_x;
		rc.ray_dir_y = game->player_direction_y + game->plane_y * rc.camera_x;
		rc.map_x = (int)(game->player_pos_x);
		rc.map_y = (int)(game->player_pos_y);
		set_delta_dist(&rc);
		calc_step_and_side(game, &rc);
		dda(game, &rc);
		calc_tex_params(game, &rc);
		vertical_texture_draw(game, &rc, x);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx->window, game->mlx->image,
		0, 0);
}
