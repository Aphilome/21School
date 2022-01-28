/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:39:02 by tbirdper          #+#    #+#             */
/*   Updated: 2022/01/28 22:39:03 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../utils/utils.h"
# include "../get_next_line/get_next_line.h"
# include "../list/list.h"

char	**map_parser_tmp(char *file_name);

t_map	*map_parser(char *file_name);

#endif
