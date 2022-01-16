#ifndef FT_DRAW_DATA_H
# define FT_DRAW_DATA_H

# include"../ft_r_im_struct/ft_r_im_struct.h"

typedef struct s_fractol_data {
	char	*type_fract;
	int		iterate_quantity_leave_circle;
}	t_fractol_data;

typedef struct s_draw_param {
	int	bits_in_one_pixel;
	int	line_size;
}	t_draw_param;

typedef struct s_mlx_data {
	t_fractol_data	fractol_data;
	t_r_im			min;
	t_r_im			max;
	t_r_im			k;
	t_draw_param	draw_param;
	void			*mlx_lib_adr;
	void			*win_adr;
	void			*image_adr;
	char			*zero_pix_adr;
	int				win_height;
	int				win_width;
}	t_mlx_data;

void	color_put_pixel(t_mlx_data *mlx_data, int x, int y, int color);

#endif
