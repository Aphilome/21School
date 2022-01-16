/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_logic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:14:24 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/24 15:15:09 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_LOGIC_H
# define READLINE_LOGIC_H

# define PROMPT "e-bash> "

# include <readline/readline.h>
# include "../utils/utils.h"

char	*read_cmd(void);

#endif
