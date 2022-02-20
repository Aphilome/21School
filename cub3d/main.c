#include <stdio.h>
#include "minilibx_opengl/mlx.h"

#include "mlx_adapter/mlx_adapter.h"

#include "parser/parser.h"

#include <math.h>
#include <sys/time.h> // DEL

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
/*
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
*/
int worldMap[mapWidth][mapHeight]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		};

//unsigned int buffer[screenHeight][screenWidth];

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


//void verLine(int x, int drawStart, int drawEnd, int side, char
//*mlx_addr, int line_length, int bytes_per_pixel)
//{
//	for (int y = 0; y < screenHeight; y++)
//	{
//		if (y >= drawStart && y < drawEnd)
//		{
//			int c;
//			if (side == 0)
//				c = 0x0000ff00; // green
//			else if (side == 1)
//				c = 0x00ff0000; // red
//			else if (side == 2)
//				c = 0x000000ff;	// blue
//			else if (side == 3)
//				c = 0x00ffff00;	// yellow
//			else
//				c = 0x00ffffff; // white
//
//			put_pixel(mlx_addr, line_length, bytes_per_pixel, x, y, c);
//		}
//		else
//		{
//			put_pixel(mlx_addr, line_length, bytes_per_pixel, x, y, 0);
//		}
//	}
//}


void	redraw(t_game *game)
{
	game->time = get_timestamp_ms();

	int w = screenWidth;
	int h = screenHeight;
	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX =
				2 * x / (double) w - 1; //x-coordinate in camera space
		double rayDirX = game->player_direction_x + game->plane_x *
				cameraX;
		double rayDirY = game->player_direction_y + game->plane_y * cameraX;

		//which box of the map we're in
		int mapX = (int)(game->player_pos_x);
		int mapY = (int)(game->player_pos_y);


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
			sideDistX = (game->player_pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player_pos_x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player_pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player_pos_y) * deltaDistY;
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

		int pitch = 100;

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2 + pitch;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2 + pitch;
		if(drawEnd >= h) drawEnd = h - 1;

		t_cardinal_directions cd = side;

		if (game->player_pos_y >= mapY &&
			game->player_pos_x >= mapX)
		{
			/*
			 * 0 3
			 * 1 2
			 * */
//			if (side == 0)
//				side = 3;
//			else
//				side = 2;

			cd = -(side - 3);
		}
		if (game->player_pos_y <= mapY&& game->player_pos_x >= mapX)
		{
			if (side == 0)
				cd = 3;
			else
				cd = 0;
		}
		if (game->player_pos_y <= mapY&& game->player_pos_x <= mapX)
		{
			if (side == 0)
				cd = 1;
			else
				cd = 0;
		}
		if (game->player_pos_y >= mapY && game->player_pos_x <= mapX)
		{
			if (side == 0)
				cd = 1;
			else
				cd = 2;
		}

		//calculate value of wallX
		double wallX; //where exactly the wall was hit
		if(side == 0) wallX = game->player_pos_y + perpWallDist * rayDirY;
		else          wallX = game->player_pos_x + perpWallDist *
				rayDirX;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)TEXTURE_WIDTH);
		if(side == 0 && rayDirX > 0) texX = TEXTURE_WIDTH - texX - 1;
		if(side == 1 && rayDirY < 0) texX = TEXTURE_WIDTH - texX - 1;


		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		double step = 1.0 * TEXTURE_HEIGHT / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - pitch - h / 2.0 + lineHeight / 2.0) * step;
		for(int y = 0; y < screenHeight; y++)
		{
			if (y >= drawStart && y < drawEnd)
			{
				// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
				int texY = (int)texPos & (TEXTURE_HEIGHT - 1);
				texPos += step;
				unsigned int color = game->map->textures[cd][TEXTURE_HEIGHT* texY + texX];
				//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
				if(side == 1) color = (color >> 1) & 8355711;

				put_pixel(game->mlx->mlx_addr, game->mlx->line_length, game->mlx->bytes_per_pixel, x, y, color);
			}
			else
			{
				put_pixel(game->mlx->mlx_addr, game->mlx->line_length, game->mlx->bytes_per_pixel, x, y, 0);
			}
		}
	}
	mlx_put_image_to_window(game->mlx, game->mlx->window, game->mlx->image, 0, 0);

	//timing for input and FPS counter
	game->oldTime = game->time;
	game->time = get_timestamp_ms();
	double frameTime = (game->time - game->oldTime);
	//frameTime is the time this frame has taken, in seconds
	printf("FPS: %i\n", (int)(1.0 / (frameTime / 1000.0))); //FPS counter

}

int	key_handler(int keycode, void *param)
{
	t_game *game;
	game = (t_game *)param;

	if (keycode == key_esc)
		exit(0);

	//move forward if no wall in front of you
	if(keycode == key_arrow_up)
	{

		if(worldMap
			[(int)(game->player_pos_x + game->player_direction_x * game->moveSpeed)]
			[(int)(game->player_pos_y)] == false)
			game->player_pos_x += game->player_direction_x * game->moveSpeed;
		if(worldMap[(int)(game->player_pos_x)][(int)(game->player_pos_y +
				game->player_direction_y * game->moveSpeed)] == false)
			game->player_pos_y += game->player_direction_y * game->moveSpeed;
	}
	//move backwards if no wall behind you
	if(keycode == key_arrow_down)
	{
		if(worldMap[(int)(game->player_pos_x - game->player_direction_x
		* game->moveSpeed)][(int)
		(game->player_pos_y)] == false) game->player_pos_x
		-= game->player_direction_x
				* game->moveSpeed;
		if(worldMap[(int)(game->player_pos_x)][(int)(game->player_pos_y - game->player_direction_y * game->moveSpeed)] == false)
			game->player_pos_y
			-= game->player_direction_y * game->moveSpeed;
	}
	//rotate to the right
	if(keycode == key_arrow_right)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = game->player_direction_x;
		game->player_direction_x = game->player_direction_x * cos(-
				game->rotSpeed) - game->player_direction_y * sin(-game->rotSpeed);
		game->player_direction_y = oldDirX * sin(-game->rotSpeed) + game->player_direction_y * cos
				(-game->rotSpeed);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(-game->rotSpeed) - game->plane_y * sin(-game->rotSpeed);
		game->plane_y = oldPlaneX * sin(-game->rotSpeed) +
				game->plane_y * cos(-game->rotSpeed);
	}
	//rotate to the left
	if(keycode == key_arrow_left)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = game->player_direction_x;
		game->player_direction_x = game->player_direction_x * cos(game->rotSpeed) - game->player_direction_y * sin(game->rotSpeed);
		game->player_direction_y = oldDirX * sin(game->rotSpeed) + game->player_direction_y * cos(game->rotSpeed);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(game->rotSpeed) - game->plane_y * sin(game->rotSpeed);
		game->plane_y = oldPlaneX * sin(game->rotSpeed) + game->plane_y * cos(game->rotSpeed);
	}

	redraw(game);

	return (0);
}


t_game *game_init(t_mlx *mlx, t_map *map)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		error_exit(ERROR_MALLOC);
	game->mlx = mlx;
	game->map = map;
	game->player_pos_x = map->player_start_pos_x;
	game->player_pos_y = map->player_start_pos_y;
	game->player_direction_x = map->player_start_direction_x;
	game->player_direction_y = map->player_start_direction_y;
	game->plane_y = 0.0;
	game->plane_x = 0.0;
	if (game->player_direction_y == 0)
		game->plane_y += 0.66 * game->player_direction_x * -1;
	if (game->player_direction_x == 0)
		game->plane_x += 0.66 * game->player_direction_y;

	game->moveSpeed = MOVE_SPEED;
	game->rotSpeed = ROTATION_SPEED;

	return game;
}

int main()
{
	t_mlx *mlx = mlx_adapter_init(screenWidth, screenHeight);
	t_map *map = map_parser("map_main.cub");
	t_game *game = game_init(mlx, map);

	redraw(game);

	mlx_key_hook(mlx->window, key_handler, game);
	mlx_loop(mlx);

	return 0;
}
