/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:30:32 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:30:34 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CD_H
# define FT_CD_H

# include <unistd.h>
# include <sys/param.h>
# include "../utils/utils.h"

void	ft_cd(t_cmd *cmd, t_env_list *env);

#endif
