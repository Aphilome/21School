#include <stdio.h>
#include "minilibx_opengl/mlx.h"
#include "parser/parser.h"


int main()
{
	void *mlx = mlx_init();
	void *screen = mlx_new_window(mlx, screenWidth, screenHeight, "Raycaster");

	double posX = 22.0, posY = 11.5;  //x and y start position
	double dirX = -1.0, dirY = 0.0; //initial direction vector
	double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

//	unsigned int texture[8];
//	for (int i = 0; i < 8; i++)
//		texture[i].resize(texWidth * texHeight);

//	(void) screen;
	for(int x = 0; x < mapWidth; x++)
	{
		//calculate ray position and direction
		double cameraX =
				2 * x / (double) mapWidth - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		(void)rayDirX;
		(void)rayDirY;

	}

	(void)time;
	(void)screen;
	(void)posX;
	(void)posY;
	(void)oldTime;

	mlx_loop(mlx);

	return 0;
}
