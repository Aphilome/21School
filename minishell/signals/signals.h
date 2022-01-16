/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:17:06 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:17:08 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include "../utils/utils.h"

void	signals_on(void);
void	signals_off(void);
void	signals_default(void);
void	signals_heredoc(void);
void	signals_std_on(void);
void	signals_std_off(void);

#endif
