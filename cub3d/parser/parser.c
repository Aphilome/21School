#include <sys/fcntl.h>
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


t_list *read_all_file(char *file_name)
{
	int			fd;
	char		*line;
	t_ret_code	code;
	t_list		*head;
	t_list		*lst_element;

	line = NULL;
	head = NULL;
	fd = open(file_name, O_RDONLY);
	code = get_next_line(fd, &line);
	while (code == code_readline)
	{
		lst_element = ft_lstnew(line);
		if (lst_element == NULL)
		{
			close(fd);
			error_exit(ERROR_MALLOC);
		}
		ft_lstadd_back(&head, lst_element);
		code = get_next_line(fd, &line);
	}
	if (code == code_error)
	{
		close(fd);
		error_exit(ERROR_MALLOC);
	}
	if (code == code_eof)
		ft_lstadd_back(&head, lst_element);
	if (close(fd) == -1)
		error_exit(ERROR_SYSTEM);
	return (head);
}

t_map *get_empty_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		error_exit(ERROR_MALLOC);
	map->map = NULL;
	map->map_lines = 0;
	map->east_texture_path = NULL;
	map->north_texture_path = NULL;
	map->west_texture_path = NULL;
	map->south_texture_path = NULL;
	map->ceiling_color[0] = 0;
	map->ceiling_color[1] = 0;
	map->ceiling_color[2] = 0;
	map->floor_color[0] = 0;
	map->floor_color[1] = 0;
	map->floor_color[2] = 0;
	return (map);
}

t_bool	is_settings_info(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] == ' ')
		i++;
	j = i;
	while (str[j] >= 'A' && str[j] <= 'Z')
		j++;
	if (i == j)
		return (false);
	i = j;
	while (str[j] == ' ')
		j++;
	if (i == j)
		return (false);
	i = j;
	while (str[j] != 0)
		j++;
	if (i == j)
		return (false);
	return (true);
}

t_bool is_map_info(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '0' || str[i] == '1' ||
		str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		i++;
	if (i == 0 || str[i] != 0)
		return (false);
	return (true);
}

t_bool is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0 || str[i] == '\n' && str[i + 1] == 0)
		return (true);
	return (false);
}

void check_file_struct(t_list *head)
{
	t_bool settings_state;

	settings_state = true;


}

t_map *map_parser(char *file_name)
{
	t_list	*head;
	t_list	*p;
	t_map	*map;
	int		size;

	map = get_empty_map();
	head = read_all_file(file_name);
	size = ft_lstsize(head);
	if (size < 9)
		error_exit(ERROR_MAP);
	p = head;
	while (p != NULL)
	{

		p = p->next;
	}

}
