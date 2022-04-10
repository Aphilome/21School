/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_logic_private.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:47:24 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 16:08:54 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_LOGIC_PRIVATE_H
# define RAYCASTING_LOGIC_PRIVATE_H

# include "raycasting_logic.h"

typedef struct s_ray_casting
{
	int						w;
	int						h;
	double					camera_x;
	double					ray_dir_x;
	double					ray_dir_y;
	int						map_x;
	int						map_y;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					perp_wall_dist;
	int						step_x;
	int						step_y;
	int						side;
	int						line_height;
	int						pitch;
	int						draw_start;
	int						draw_end;
	t_cardinal_directions	cd;
	double					wall_x;
	int						tex_x;
}	t_ray_casting;

void	calc_step_and_side(t_game *game, t_ray_casting *rc);
void	dda(t_game *game, t_ray_casting *rc);
void	calc_tex_params(t_game *game, t_ray_casting *rc);

#endif
