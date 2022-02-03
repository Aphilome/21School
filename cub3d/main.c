#include <stdio.h>
#include "minilibx_opengl/mlx.h"
#include "parser/parser.h"

#include <math.h>
#include <sys/time.h> // DEL

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64

int worldMap[mapWidth][mapHeight]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
				{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

unsigned int buffer[screenHeight][screenWidth];

double	get_timestamp_ms(void)
{
	struct timeval	now;
	int				res;

	res = gettimeofday(&now, NULL);
	if (res != 0)
		return (0);
	return (double)(now.tv_sec * 1000 + now.tv_usec / 1000);
}


void	put_pixel(char *mlx_addr, int line_length, int bytes_per_pixel, int x,
				  int y, int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)(mlx_addr
						   + (y * line_length + x * bytes_per_pixel));
	*dst = color;
}


void verLine(int x, int drawStart, int drawEnd, ColorRGB color, char
*mlx_addr, int line_length, int bytes_per_pixel)
{
	// x - vertival?
	for (int y = drawStart; y < drawEnd; y++)
	{
		int c = 76567;

		c *= (int)color+1;


		put_pixel(mlx_addr, line_length, bytes_per_pixel, x, y, c);
	}


}

int main()
{
	void *mlx = mlx_init();
	if (mlx == NULL)
		error_exit(ERROR_MLX);
	void *mlx_win = mlx_new_window(mlx, screenWidth, screenHeight, "Raycaster");
	if (mlx_win == NULL)
		error_exit(ERROR_MLX);
	void *mlx_img = mlx_new_image(mlx, screenWidth, screenHeight);
	if (mlx_img == NULL)
		error_exit(ERROR_MLX);



	int bytes_per_pixel;
	int line_length;
	int endian;
	char *mlx_addr = mlx_get_data_addr(
			mlx_img, &bytes_per_pixel,
			&line_length, &endian);
	bytes_per_pixel /= 8;




	double posX = 22.0, posY = 11.5;  //x and y start position
	double dirX = -1.0, dirY = 0.0; //initial direction vector
	double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

//	unsigned int texture[8];
//	for (int i = 0; i < 8; i++)
//		texture[i].resize(texWidth * texHeight);

//	(void) screen;


	int w = screenWidth;
	int h = screenHeight;
	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX =
				2 * x / (double) w - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

        //which box of the map we're in
        int mapX = (int)(posX);
        int mapY = (int)(posY);


        //length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double perpWallDist;

        //what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; //was there a wall hit?
        int side; //was a NS or a EW wall hit?
        //calculate step and initial sideDist
        if(rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if(rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        //perform DDA
        while(hit == 0)
        {
            //jump to next map square, either in x-direction, or in y-direction
            if(sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            //Check if ray has hit a wall
            if(worldMap[mapX][mapY] > 0) hit = 1;
        }

        //perform DDA
        while(hit == 0)
        {
            //jump to next map square, either in x-direction, or in y-direction
            if(sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            //Check if ray has hit a wall
            if(worldMap[mapX][mapY] > 0) hit = 1;
        }

        if(side == 0) perpWallDist = (sideDistX - deltaDistX);
        else          perpWallDist = (sideDistY - deltaDistY);

        //Calculate height of line to draw on screen
        int lineHeight = (int)(h / perpWallDist);

        //calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + h / 2;
        if(drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + h / 2;
        if(drawEnd >= h) drawEnd = h - 1;

        //choose wall color
        ColorRGB color;
        switch(worldMap[mapX][mapY])
        {
            case 1:  color = RGB_Red;    break; //red
            case 2:  color = RGB_Green;  break; //green
            case 3:  color = RGB_Blue;   break; //blue
            case 4:  color = RGB_White;  break; //white
            default: color = RGB_Yellow; break; //yellow
        }

        //give x and y sides different brightness
        if(side == 1) {color = color / 2;}

        //draw the pixels of the stripe as a vertical line
        verLine(x, drawStart, drawEnd, color, mlx_addr, line_length, bytes_per_pixel);

    }

    //timing for input and FPS counter
    oldTime = time;
    time = get_timestamp_ms();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    printf("= fps: %f\n", 1.0 / frameTime); //FPS counter

    //redraw();
    //cls();
    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

	(void)moveSpeed;
	(void)rotSpeed;

	mlx_put_image_to_window(mlx, mlx_win, mlx_img, 0, 0);


	mlx_loop(mlx);

	return 0;
}

/*
void keys()
{
    readKeys();
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
        if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
        if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
        if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
        if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
        //both camera direction and camera plane must be rotated
        double oldDirX = dirX;
        dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
        dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
        planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
        //both camera direction and camera plane must be rotated
        double oldDirX = dirX;
        dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
        dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
        double oldPlaneX = planeX;
        planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
        planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
}
 */