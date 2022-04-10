/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:04:33 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 01:32:22 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_life_circle.h"

void	skip_eat(t_philo *philo);
void	philo_get_fork(t_philo *philo, t_semaphore *fork);
void	philo_eating(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	philo_thinking(t_philo *philo);

void	philo_life_circle(t_philo *philo)
{
	philo->last_eat_time = get_time_ms();
	philo->state = thinking;
	while (1)
	{
		if (philo->how_much_eat == 0 && philo->id % 2 != 0)
			skip_eat(philo);
		philo_get_fork(philo, philo->forks);
		philo_get_fork(philo, philo->forks);
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
}

void	*caretaker_life_circle(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (philo->state != init && get_time_ms() > philo->last_eat_time
			+ philo->input->time_to_die)
		{
			sem_wait(philo->input->printing);
			print_philo_time(philo->id);
			ft_putstr(" died\n");
			sem_post(philo->input->printing);
			exit(exit_philo_died);
		}
		if (philo->input->number_must_eat != -1 && philo->how_much_eat
			>= philo->input->number_must_eat)
			exit(exit_philo_done);
		usleep(50);
	}
}
