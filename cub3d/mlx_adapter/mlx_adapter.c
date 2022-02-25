/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_adapter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:13:15 by tbirdper          #+#    #+#             */
/*   Updated: 2022/02/19 12:15:46 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_adapter.h"

t_mlx	*mlx_adapter_init(int scrWidth, int scrHeight)
{
	t_mlx	*mlx;
	int		endian;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		error_exit(ERROR_MALLOC);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		error_exit(ERROR_MLX);
	mlx->window = mlx_new_window(mlx->mlx, scrWidth, scrHeight, PROJECT_NAME);
	if (mlx->window == NULL)
		error_exit(ERROR_MLX);
	mlx->image = mlx_new_image(mlx->mlx, scrWidth, scrHeight);
	if (mlx->image == NULL)
		error_exit(ERROR_MLX);
	mlx->mlx_addr = mlx_get_data_addr(
			mlx->image, &mlx->bytes_per_pixel,
			&mlx->line_length, &endian);
	mlx->bytes_per_pixel /= 8;
	return (mlx);
}
