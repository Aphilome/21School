#include "ft_fractol_draw.h"

int	ft_r_g_b_calc(int iteration, t_mlx_data *mlx_data)
{
	int		red;
	int		green;
	int		blue;
	int		color;
	double	t;

	t = (double) iteration
		/ (double)mlx_data->fractol_data.iterate_quantity_leave_circle;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = red;
	color = color << 8;
	color += green;
	color = color << 8;
	color += blue;
	return (color);
}

int	ft_iteration_quantity(t_mlx_data *mlx_data, t_r_im *c,
							 void (f)(t_r_im*, t_r_im*, t_r_im*))
{
	t_r_im	z;
	int		iteration;

	z.r = c->r;
	z.im = c->im;
	iteration = 0;
	while (z.r * z.r + z.im * z.im <= 4 && iteration
		< mlx_data->fractol_data.iterate_quantity_leave_circle)
	{
		f(&z, c, &mlx_data->k);
		iteration++;
	}
	return (iteration);
}

void	ft_fractal_drawer(t_mlx_data *mlx_data,
			void (f)(t_r_im*, t_r_im*, t_r_im*))
{
	t_r_im	factor;
	t_r_im	c;
	int		x;
	int		y;

	factor.r = (mlx_data->max.r - mlx_data->min.r) / (mlx_data->win_width - 1);
	factor.im = (mlx_data->max.im - mlx_data->min.im)
		/ (mlx_data->win_height - 1);
	y = 0;
	while (y < mlx_data->win_height)
	{
		c.im = mlx_data->max.im - y * factor.im;
		x = 0;
		while (x < mlx_data->win_width)
		{
			c.r = mlx_data->min.r + x * factor.r;
			color_put_pixel(mlx_data, x, y,
				ft_r_g_b_calc(ft_iteration_quantity(mlx_data, &c, f),
					mlx_data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data->mlx_lib_adr, mlx_data->win_adr,
		mlx_data->image_adr, 0, 0);
}
