/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:44:32 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 22:44:46 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLER_PRIVATE_H
# define KEY_HANDLER_PRIVATE_H

# include "key_handler.h"

void	forward(t_game *game);
void	backwards(t_game *game);
void	left(t_game *game);
void	right(t_game *game);
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);

#endif
