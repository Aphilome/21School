/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:30:29 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 13:34:05 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include <sys/fcntl.h>
# include "parser.h"
# include "../minilibx_opengl/mlx.h"

t_bool	undefined_settings(void);
void	no_settings_setter(t_map *map, char *value);
void	so_settings_setter(t_map *map, char *value);
void	we_settings_setter(t_map *map, char *value);
void	ea_settings_setter(t_map *map, char *value);
void	f_settings_setter(t_map *map, char *value);
void	c_settings_setter(t_map *map, char *value);
void	set_texture(t_map *map, char *path, t_cardinal_directions cd);

t_list	*read_all_file(char *file_name);

t_bool	is_settings_info_line(char *str);
t_bool	is_map_info_line(char *str);
t_bool	is_empty_line(char *str);

t_list	*init_settings(t_list *head, t_map *map);
void	parse_settings(t_map *map, char *str);
t_bool	settings_setter(char *str, t_map *map, char *key,
			void (*setter)(t_map *, char *));

void	map_init(t_map *map, t_list *head);
void	map_validator(t_map *map);

#endif
