#include "ft_draw_data.h"

void	color_put_pixel(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*pixel_color;

	pixel_color = mlx_data->zero_pix_adr
		+ (x * (mlx_data->draw_param.bits_in_one_pixel)
			/ 8 + y * mlx_data->draw_param.line_size);
	*(unsigned int *)pixel_color = color;
}
