/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:03:43 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/03 14:04:06 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DATA_H
# define PHILO_DATA_H

# include "../philo_life_circle/philo_life_circle.h"

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef enum e_philo_deals
{
	init = 0,
	has_taken_a_fork = 1,
	eating = 2,
	sleeping = 3,
	thinking = 4,
	death = 5
}	t_philo_deals;

typedef struct s_input
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_must_eat;
}	t_input;

typedef struct s_philo
{
	t_input			*input;
	t_mutex			*printing;
	t_mutex			*right;
	t_mutex			*left;
	pthread_t		thread;
	size_t			last_eat_time;
	int				id;
	int				how_much_eat;
	t_philo_deals	state;
}	t_philo;

#endif
