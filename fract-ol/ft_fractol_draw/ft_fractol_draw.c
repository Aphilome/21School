#include "ft_fractol_draw.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	set_new_z_mandelbrot(t_r_im *z, t_r_im *c, t_r_im *k)
{
	double	real;
	double	imagine;

	(void)k;
	real = z->r * z->r - z->im * z->im + c->r;
	imagine = 2.0 * z->r * z->im + c->im;
	z->r = real;
	z->im = imagine;
}

void	set_new_perpendicular_mandelbrot(t_r_im *z, t_r_im *c, t_r_im *k)
{
	double	real;
	double	imagine;

	(void)k;
	real = z->r * z->r - z->im * z->im + c->r;
	if (z->r < 0)
		imagine = -2.0 * (0 - z->r) * z->im + c->im;
	else
		imagine = -2.0 * z->r * z->im + c->im;
	z->r = real;
	z->im = imagine;
}

void	set_new_z_julia(t_r_im *z, t_r_im *c, t_r_im *k)
{
	double	real;
	double	imagine;

	(void)c;
	real = z->r * z->r - z->im * z->im + k->r;
	imagine = 2.0 * z->r * z->im + k->im;
	z->r = real;
	z->im = imagine;
}

void	choose_fractol(t_mlx_data *mlx_data)
{
	if (mlx_data->fractol_data.type_fract[0] == 'm'
		&& mlx_data->fractol_data.type_fract[1] == 0)
		ft_fractal_drawer(mlx_data, set_new_z_mandelbrot);
	else if (mlx_data->fractol_data.type_fract[0] == 'j'
		&& mlx_data->fractol_data.type_fract[1] == 0)
		ft_fractal_drawer(mlx_data, set_new_z_julia);
	else if (mlx_data->fractol_data.type_fract[0] == 'p'
		&& mlx_data->fractol_data.type_fract[1] == 0)
		ft_fractal_drawer(mlx_data, set_new_perpendicular_mandelbrot);
}
