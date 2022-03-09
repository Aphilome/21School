/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:31:14 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 13:31:15 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loader_private.h"

int	get_color(int color_mas[3])
{
	int	color;

	color = (color_mas[0] << 16) + (color_mas[1] << 8) + (color_mas[2]);
	return (color);
}

void	colors_load(t_game *game)
{
	game->ceiling_color = get_color(game->map->ceiling_color);
	game->floor_color = get_color(game->map->floor_color);
}
