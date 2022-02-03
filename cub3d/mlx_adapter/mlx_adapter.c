#include "mlx_adapter.h"

t_mlx *mlx_adapter_init(int screenWidth, int screenHeight)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		error_exit(ERROR_MALLOC);
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		error_exit(ERROR_MLX);
	mlx->window = mlx_new_window(mlx->mlx, screenWidth, screenHeight, PROJECT_NAME);
	if (mlx->window == NULL)
		error_exit(ERROR_MLX);
	mlx->image = mlx_new_image(mlx->mlx, screenWidth, screenHeight);
	if (mlx->image == NULL)
		error_exit(ERROR_MLX);



}