#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <mlx.h>
#include <stdlib.h>
#include "ft_draw_data/ft_draw_data.h"
#include "ft_fractol_draw/ft_fractol_draw.h"

void	exit_with_msg(void)
{
	printf("%s\n", strerror(errno));
	exit(0);
}

void	mlx(t_mlx_data *mlx_data)
{
	mlx_data->mlx_lib_adr = mlx_init();
	if (mlx_data->mlx_lib_adr == NULL)
		exit_with_msg();
	mlx_data->win_adr = mlx_new_window(mlx_data->mlx_lib_adr,
			mlx_data->win_width, mlx_data->win_height, "fractol");
	if (mlx_data->win_adr == NULL)
	{
		free(mlx_data->mlx_lib_adr);
		exit_with_msg();
	}
	mlx_data->image_adr = mlx_new_image(mlx_data->mlx_lib_adr,
			mlx_data->win_width, mlx_data->win_height);
	if (mlx_data->image_adr == NULL)
	{
		free(mlx_data->mlx_lib_adr);
		free(mlx_data->win_adr);
		exit_with_msg();
	}
}

void	initialize(t_mlx_data *mlx_data, char **argv)
{
	int	tmp;

	mlx_data->min.r = -2.0;
	mlx_data->max.r = 2.0;
	mlx_data->min.im = -2.0;
	mlx_data->max.im = 2.0;
	mlx_data->win_height = 400;
	mlx_data->win_width = 400;
	mlx_data->fractol_data.iterate_quantity_leave_circle = 40;
	mlx_data->fractol_data.type_fract = argv[1];
	mlx(mlx_data);
	mlx_data->zero_pix_adr = mlx_get_data_addr(
			mlx_data->image_adr, &mlx_data->draw_param.bits_in_one_pixel,
			&mlx_data->draw_param.line_size, &tmp);
}

int	main(int argc, char **argv)
{
	t_mlx_data	mlx_data;

	if (argc != 2)
	{
		printf("You should enter one of the next"
			   "command:\nm - Mandelbrot fractal\nj - Julia fractal\np - "
			   "Perpendicular Mandelbrot fractal\n");
		exit(0);
	}
	initialize(&mlx_data, argv);
	choose_fractol(&mlx_data);
	mlx_mouse_hook(mlx_data.win_adr, mouse_handler, &mlx_data);
	mlx_key_hook(mlx_data.win_adr, key_hook, &mlx_data);
	mlx_hook(mlx_data.win_adr, 6, 0, julia_motion_handler, &mlx_data);
	mlx_loop(mlx_data.mlx_lib_adr);
	return (0);
}
