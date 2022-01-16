/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:35 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:32:37 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <sys/stat.h>
# include "../utils/utils.h"
# include "../ft_echo/ft_echo.h"
# include "../ft_pwd/ft_pwd.h"
# include "../ft_cd/ft_cd.h"
# include "../ft_export/ft_export.h"
# include "../ft_env/ft_env.h"
# include "../ft_unset/ft_unset.h"
# include "../signals/signals.h"
# include "../ft_exit/ft_exit.h"

void	run_commands(t_cmd **cmds, t_env_list **env);
void	clear_cmds(t_cmd **cmds);

#endif
