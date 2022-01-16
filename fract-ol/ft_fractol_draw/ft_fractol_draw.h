#ifndef FT_FRACTOL_DRAW_H
# define FT_FRACTOL_DRAW_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "../ft_draw_data/ft_draw_data.h"

void	set_new_z_mandelbrot(t_r_im *z, t_r_im *c, t_r_im *k);
void	set_new_perpendicular_mandelbrot(t_r_im *z, t_r_im *c, t_r_im *k);
void	set_new_z_julia(t_r_im *z, t_r_im *c, t_r_im *k);
void	ft_fractal_drawer(t_mlx_data *mlx_data, void (f)(t_r_im*, t_r_im*,
				t_r_im*));
void	choose_fractol(t_mlx_data *mlx_data);
double	interpolate(double start, double end, double interpolation);
int		mouse_handler(int button, int x, int y, void *param);
int		key_hook(int keycode, void *param);
int		julia_motion_handler(int x, int y, void *param);

#endif
