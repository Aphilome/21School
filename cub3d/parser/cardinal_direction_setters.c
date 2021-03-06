/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_direction_setters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:30:14 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/28 22:30:16 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_private.h"

void	no_settings_setter(t_map *map, char *value)
{
	map->north_texture_path = ft_strdup(value);
}

void	so_settings_setter(t_map *map, char *value)
{
	map->south_texture_path = ft_strdup(value);
}

void	we_settings_setter(t_map *map, char *value)
{
	map->west_texture_path = ft_strdup(value);
}

void	ea_settings_setter(t_map *map, char *value)
{
	map->east_texture_path = ft_strdup(value);
}

t_bool	undefined_settings(void)
{
	error_exit(ERROR_UNDEFINED);
	return (true);
}
