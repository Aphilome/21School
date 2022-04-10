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

int	key_handler(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == key_esc)
		exit(0);
	if (keycode == key_w)
		forward(game);
	if (keycode == key_s)
		backwards(game);
	if (keycode == key_a)
		left(game);
	if (keycode == key_d)
		right(game);
	if (keycode == key_arrow_right)
		rotate_right(game);
	if (keycode == key_arrow_left)
		rotate_left(game);
	redraw(game);
	return (0);
}
