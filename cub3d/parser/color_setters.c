/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:46:29 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/29 22:46:56 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

int	get_color_len(int color)
{
	if (color >= 0 && color <= 9)
		return (1);
	if (color >= 10 && color <= 99)
		return (2);
	return (3);
}

void	color_parser(char *value, int color[3])
{
	int	part;
	int	len;

	part = 0;
	while (part < 3)
	{
		color[part] = ft_simple_atoi(value);
		if (color[part] > 255)
			error_exit(ERROR_SETTINGS);
		len = get_color_len(color[part]);
		value = &(value[len + 1]);
		part++;
	}
		//pause();
}

void	validator_color(char *value)
{
	int	i;
	int	len;
	int	comma;

	len = ft_strlen(value);
	if (len < 5 || len > 11 || value[0] == ',' || value[len - 1] == ',')
		error_exit(ERROR_SETTINGS);
	comma = 0;
	i = 0;
	while (value[i] != 0)
	{
		if (value[i] == ',' && value[i + 1] != ',')
			comma++;
		else if (value[i] < '0' || value[i] > '9')
			error_exit(ERROR_SETTINGS);
		i++;
	}
	if (comma != 2)
		error_exit(ERROR_SETTINGS);
}

void	f_settings_setter(t_map *map, char *value)
{
	validator_color(value);
	color_parser(value, map->floor_color);
}

void	c_settings_setter(t_map *map, char *value)
{
	validator_color(value);
	color_parser(value, map->ceiling_color);
}
