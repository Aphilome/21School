/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:03:06 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/03 14:03:15 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZER_H
# define INITIALIZER_H

# include <stdlib.h>
# include <pthread.h>
# include "../philo_data/philo_data.h"

t_philo	*philos_initializer(t_input *input, t_mutex *forks, t_mutex *printing);
t_mutex	*forks_initializer(int number_of_philo);

#endif
