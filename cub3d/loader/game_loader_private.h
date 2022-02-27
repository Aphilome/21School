/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loader_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:33:28 by tbirdper          #+#    #+#             */
/*   Updated: 2022/02/27 14:33:34 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOADER_PRIVATE_H
# define GAME_LOADER_PRIVATE_H

# include "game_loader.h"
# include "../minilibx_opengl/mlx.h"

void	textures_load(t_game *game);
void	colors_load(t_game *game);

#endif
