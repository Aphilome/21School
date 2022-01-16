#include "ft_fractol_draw.h"

void	ft_scrl_up_scrl_down_interpolate_mouse_hook(t_mlx_data *mlx_data, t_r_im
			*mouse, double scale, int button)
{
	if (button == 5)
		scale = 1.0 / 0.75;
	else if (button == 4)
		scale = 1.0 / 1.25;
	mlx_data->min.r = interpolate(mouse->r, mlx_data->min.r, scale);
	mlx_data->min.im = interpolate(mouse->im, mlx_data->min.im, scale);
	mlx_data->max.r = interpolate(mouse->r, mlx_data->max.r, scale);
	mlx_data->max.im = interpolate(mouse->im, mlx_data->max.im, scale);
}

int	mouse_handler(int button, int x, int y, void *param)
{
	t_mlx_data	*mlx_data;
	t_r_im		mouse;
	double		scale;

	scale = 1;
	if (button != 5 && button != 4)
		return (0);
	mlx_data = (t_mlx_data *)param;
	mouse.r = (double)x
		/ (mlx_data->win_width / (mlx_data->max.r - mlx_data->min.r))
		+ mlx_data->min.r;
	mouse.im = (double)y
		/ (mlx_data->win_height / (mlx_data->max.im - mlx_data->min.im))
		* (-1) + mlx_data->max.im;
	ft_scrl_up_scrl_down_interpolate_mouse_hook(mlx_data, &mouse,
		scale, button);
	choose_fractol(mlx_data);
	return (0);
}

void	ft_esc_left_right_up_key_hook(int keycode, t_mlx_data *mlx_data, t_r_im
*r_im)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
	{
		mlx_data->min.r -= r_im->r * 5 / 100;
		mlx_data->max.r -= r_im->r * 5 / 100;
	}
	else if (keycode == 124)
	{
		mlx_data->min.r += r_im->r * 5 / 100;
		mlx_data->max.r += r_im->r * 5 / 100;
	}
	else if (keycode == 126)
	{
		mlx_data->min.im += r_im->im * 5 / 100;
		mlx_data->max.im += r_im->im * 5 / 100;
	}
}

int	key_hook(int keycode, void *param)
{
	t_mlx_data	*mlx_data;
	t_r_im		r_im;

	mlx_data = (t_mlx_data *)param;
	r_im.r = fabs(mlx_data->max.r - mlx_data->min.r);
	r_im.im = fabs(mlx_data->max.im - mlx_data->min.im);
	ft_esc_left_right_up_key_hook(keycode, mlx_data, &r_im);
	if (keycode == 125)
	{
		mlx_data->min.im -= r_im.im * 5 / 100;
		mlx_data->max.im -= r_im.im * 5 / 100;
	}
	else if (keycode == 69)
		mlx_data->fractol_data.iterate_quantity_leave_circle += 10;
	else if (keycode == 78)
		mlx_data->fractol_data.iterate_quantity_leave_circle -= 10;
	choose_fractol(mlx_data);
	return (0);
}

int	julia_motion_handler(int x, int y, void *param)
{
	t_mlx_data	*mlx_data;

	mlx_data = (t_mlx_data *)param;
	mlx_data->k.r = 4 * ((double)x / mlx_data->win_width - 5.0 / 10);
	mlx_data->k.im = 4 * ((double)(mlx_data->win_height - y)
			/ mlx_data->win_height - 5.0 / 10);
	choose_fractol(mlx_data);
	return (0);
}
