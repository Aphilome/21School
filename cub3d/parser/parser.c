/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:30:33 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/29 22:47:18 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

void	print_file(t_list *head)
{
	print_strl("=======================");
	while (head != NULL)
	{
		print_strl(head->content);
		head = head->next;
	}
	print_strl("=======================");
}

void	print_c(int c)
{
	char	one = (c / 100) + '0';
	char	two = ((c / 10) % 10) + '0';
	char	three = (c % 10) + '0';

	if (one != '0')
		write(1, &one, 1);
	if (!(two == '0' && one == '0'))
		write(1, &two, 1);
	write(1, &three, 1);
}

void	print_color(int color[3])
{
	print_c(color[0]);
	print_str(",");
	print_c(color[1]);
	print_str(",");
	print_c(color[2]);
	print_strl("");
}

void	print_map(t_map *map)
{
	print_strl("#######################");
	if (map == NULL)
		print_strl("map NULL");
	if (map->north_texture_path == NULL)
		print_strl("map north_texture_path NULL");
	print_str("NO: ");
	print_strl(map->north_texture_path);
	print_str("SO: ");
	print_strl(map->south_texture_path);
	print_str("WE: ");
	print_strl(map->west_texture_path);
	print_str("EA: ");
	print_strl(map->east_texture_path);
	print_strl("");
	print_str("C: ");
	print_color(map->ceiling_color);
	print_str("F: ");
	print_color(map->floor_color);
	print_strl("");
	print_nbr(map->map_height);
	print_str("x");
	print_nbr(map->map_width);
	print_strl(" (h x w)");


	print_strl("#######################");
}

t_map	*get_empty_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		error_exit(ERROR_MALLOC);
	map->map = NULL;
	map->east_texture_path = NULL;
	map->north_texture_path = NULL;
	map->west_texture_path = NULL;
	map->south_texture_path = NULL;
	map->ceiling_color[0] = -1;
	map->ceiling_color[1] = -1;
	map->ceiling_color[2] = -1;
	map->floor_color[0] = -1;
	map->floor_color[1] = -1;
	map->floor_color[2] = -1;
	map->map_width = 0;
	map->map_height = 0;


	map->player_start_pos_x = 22; // TODO: HARDCODE
	map->player_start_pos_y = 15;

	map->player_start_pos_x += 1 / 1e10;
	map->player_start_pos_y += 1 / 1e10;

	map->player_start_direction_x = -1; // TODO: HARDCODE
	map->player_start_direction_y = 0;


	return (map);
}

void	parse_settings(t_map *map, char *str)
{
	if (settings_setter(str, map, "NO", no_settings_setter)
		|| settings_setter(str, map, "SO", so_settings_setter)
		|| settings_setter(str, map, "WE", we_settings_setter)
		|| settings_setter(str, map, "EA", ea_settings_setter)
		|| settings_setter(str, map, "F", f_settings_setter)
		|| settings_setter(str, map, "C", c_settings_setter)
		|| undefined_settings())
		;
}


void	texture_filler_tmp(t_map	*map)
{
	for(int x = 0; x < TEXTURE_WIDTH; x++)
		for(int y = 0; y < TEXTURE_HEIGHT; y++)
		{
			int xorcolor = (x * 256 / TEXTURE_WIDTH) ^ (y * 256 / TEXTURE_HEIGHT);
			int xycolor = y * 128 / TEXTURE_HEIGHT + x * 128 / TEXTURE_WIDTH;
			map->textures[0][TEXTURE_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEXTURE_WIDTH - y); //flat red texture with black cross
			map->textures[1][TEXTURE_WIDTH * y + x] = xycolor + 256 *xycolor+ 65536 * xycolor; //sloped greyscale
			map->textures[2][TEXTURE_WIDTH * y + x] = 256 * xycolor +65536 *xycolor; //sloped yellow gradient
			map->textures[3][TEXTURE_WIDTH * y + x] = xorcolor + 256 *xorcolor + 65536 * xorcolor; //xor greyscale
		}
}

t_map	*map_parser(char *file_name)
{
	t_list	*head;
	t_list	*map_start;
	t_map	*map;

	map = get_empty_map();
	head = read_all_file(file_name);
	print_file(head);
	if (ft_lstsize(head) < 9)
		error_exit(ERROR_MAP);
	map_start = init_settings(head, map);
	map_init(map, map_start);

	texture_filler_tmp(map);

	print_map(map);
	return (map);
}
