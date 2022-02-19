/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_adapter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:14:37 by tbirdper          #+#    #+#             */
/*   Updated: 2022/02/19 12:14:38 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ADAPTER_H
# define MLX_ADAPTER_H

# include "../minilibx_opengl/mlx.h"
# include "../utils/utils.h"

t_mlx	*mlx_adapter_init(int screenWidth, int screenHeight);

#endif
