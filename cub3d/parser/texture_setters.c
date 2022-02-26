#include "parser_private.h"


//void set_texture(t_map *map, char *path, t_cardinal_directions cd)
//{
//	char	buf[TEXTURE_SIZE];
//	int fd;
//	int i;
//	ssize_t count;
//
//	fd = open(path, O_RDONLY);
//	if (fd == -1)
//		error_exit(ERROR_OPEN_FILE);
//	print_str("i want: ");
//	print_nbrl(TEXTURE_SIZE * 3);
//	count = read(fd, (void *)buf, TEXTURE_SIZE * 3);
//	print_str("i get: ");
//	print_nbrl(count);
//
//	if (count != TEXTURE_SIZE * 3)
//		error_exit(ERROR_READ_FILE);
//	i = 0;
//	while (i < TEXTURE_SIZE * 3)
//	{
//		map->textures[cd][i] = buf[i];
//		i++;
//	}
//
//	if (close(fd) == -1)
//		error_exit(ERROR_CLOSE_FILE);
//}
