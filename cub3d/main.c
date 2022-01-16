#include <stdio.h>

#include "minilibx_opengl/mlx.h"

int main()
{
	printf("Start\n");

	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, 640, 480, "test");

	(void) window;

	mlx_loop(mlx);

	return 0;
}
