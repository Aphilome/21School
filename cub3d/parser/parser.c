#include "parser.h"

// пока-что хардкод тебе чтоб не ждала парсер
char **map_parser_tmp(char *file_name)
{
	(void)file_name;
	int height = 5;
	int width = 5;

	char **map = malloc(sizeof(char *) * (height + 1));
	// if map == NULL return null;

	map[0] = malloc(sizeof(char) * (width + 1));
	map[1] = malloc(sizeof(char) * (width + 1));
	map[2] = malloc(sizeof(char) * (width + 1));
	map[3] = malloc(sizeof(char) * (width + 1));
	map[4] = malloc(sizeof(char) * (width + 1));
	map[5] = NULL;

	map[0][0] = '1'; map[0][1] = '1'; map[0][2] = '1'; map[0][3] = '1'; map[0][4] = '1'; map[0][5] = 0;
	map[1][0] = '1'; map[1][1] = '0'; map[1][2] = '1'; map[1][3] = '0'; map[1][4] = '1'; map[1][5] = 0;
	map[2][0] = '1'; map[2][1] = '0'; map[2][2] = '1'; map[2][3] = '1'; map[2][4] = '1'; map[2][5] = 0;
	map[3][0] = '1'; map[3][1] = '0'; map[3][2] = '0'; map[3][3] = '0'; map[3][4] = '1'; map[3][5] = 0;
	map[4][0] = '1'; map[4][1] = '1'; map[4][2] = '1'; map[4][3] = '1'; map[4][4] = '1'; map[4][5] = 0;

	return (map); // null, если ошибка какая-то
}
