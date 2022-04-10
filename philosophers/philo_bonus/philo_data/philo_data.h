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

# include <pthread.h>
# include <semaphore.h>

typedef sem_t			t_semaphore;
typedef pthread_t		t_thread;

typedef enum e_exit_code
{
	exit_sys_error = 0,
	exit_philo_died = 1,
	exit_philo_done = 2
}	t_exit_code;

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
	t_semaphore			*overlap;
	t_semaphore			*printing;
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_must_eat;
}	t_input;

typedef struct s_philo
{
	t_input			*input;
	t_semaphore		*forks;
	pthread_t		monitor_thread;
	size_t			last_eat_time;
	pid_t			pid;
	int				id;
	int				how_much_eat;
	t_philo_deals	state;
}	t_philo;

#endif
