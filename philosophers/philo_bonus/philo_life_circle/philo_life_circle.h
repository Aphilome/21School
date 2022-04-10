/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_circle.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:04:47 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/03 14:04:55 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIFE_CIRCLE_H
# define PHILO_LIFE_CIRCLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../philo_data/philo_data.h"
# include "../utils/utils.h"

void	philo_life_circle(t_philo *philo);
void	*caretaker_life_circle(void *arg);

#endif
