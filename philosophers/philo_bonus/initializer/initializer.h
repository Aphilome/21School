/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:03:06 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/04 22:34:08 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H

# include <stdlib.h>
# include <pthread.h>
# include "../philo_data/philo_data.h"
# include "../utils/utils.h"

t_boolean	forks_philo_init(t_input *input, t_philo **philo,
				t_semaphore **forks);
t_philo		*philos_initializer(t_input *input, t_semaphore *forks);
t_semaphore	*forks_initializer(t_input *input);

#endif
