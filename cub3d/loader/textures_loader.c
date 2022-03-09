/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:31:29 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 13:32:13 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loader_private.h"

char	*get_texture_ptr(void *tex_img)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*tex_ptr;

	tex_ptr = mlx_get_data_addr(tex_img, &bits_per_pixel, &size_line, &endian);
	if (bits_per_pixel != 32 || size_line != 256 || endian != 0)
		error_exit(ERROR_PIXEL_FILE);
	return (tex_ptr);
}

char	*load_texture(t_mlx *mlx, char *filepath)
{
	int		width;
	int		height;
	void	*tex_img;

	tex_img = mlx_xpm_file_to_image(mlx->mlx, filepath, &width, &height);
	if (tex_img == NULL)
		error_exit(ERROR_OPEN_FILE);
	if (width != TEXTURE_WIDTH || height != TEXTURE_HEIGHT)
		error_exit(ERROR_SIZE_FILE);
	return (get_texture_ptr(tex_img));
}

void	textures_load(t_game *game)
{
	game->textures[cd_north]
		= load_texture(game->mlx, game->map->north_texture_path);
	game->textures[cd_east]
		= load_texture(game->mlx, game->map->east_texture_path);
	game->textures[cd_south]
		= load_texture(game->mlx, game->map->south_texture_path);
	game->textures[cd_west]
		= load_texture(game->mlx, game->map->west_texture_path);
}
