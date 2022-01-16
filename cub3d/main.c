#include <stdio.h>
#include "minilibx_opengl/mlx.h"
#include "parser/parser.h"


int main()
{
	printf("Start\n");
	char **map = map_parser_tmp("test");
	if (map == NULL)
	{
		printf("Error\n");
		return 1;
	}
	int i = 0;
	while (map[i] != 0)
		printf("%s\n", map[i++]);


	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, 640, 480, "test");

	(void) window;

	mlx_loop(mlx);

	return 0;
}
