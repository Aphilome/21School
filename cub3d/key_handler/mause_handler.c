/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 22:02:56 by tbirdper          #+#    #+#             */
/*   Updated: 2022/03/09 22:44:50 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_handler_private.h"

int	mouse_handler(int x, int y, void *param)
{
	t_game	*game;

	(void)y;
	game = (t_game *)param;
	if (x == game->mouse_old_x)
		return (0);
	if (x > game->mouse_old_x)
		rotate_right(game);
	else
		rotate_left(game);
	game->mouse_old_x = x;
	redraw(game);
	return (0);
}
