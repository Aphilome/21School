/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:41:43 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 01:31:46 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_life_circle.h"

void	skip_eat(t_philo *philo)
{
	ms_sleep(philo->input->time_to_eat);
}

void	philo_get_fork(t_philo *philo, t_semaphore *fork)
{
	philo->state = has_taken_a_fork;
	sem_wait(fork);
	sem_wait(philo->input->printing);
	print_philo_time(philo->id);
	ft_putstr(" has taken a fork\n");
	sem_post(philo->input->printing);
}

void	philo_eating(t_philo *philo)
{
	philo->last_eat_time = get_time_ms();
	philo->state = eating;
	sem_wait(philo->input->printing);
	print_philo_time(philo->id);
	ft_putstr(" is eating\n");
	sem_post(philo->input->printing);
	ms_sleep(philo->input->time_to_eat);
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	philo_sleeping(t_philo *philo)
{
	philo->state = sleeping;
	sem_wait(philo->input->printing);
	print_philo_time(philo->id);
	ft_putstr(" is sleeping\n");
	sem_post(philo->input->printing);
	philo->how_much_eat++;
	ms_sleep(philo->input->time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	philo->state = thinking;
	sem_wait(philo->input->printing);
	print_philo_time(philo->id);
	ft_putstr(" is thinking\n");
	sem_post(philo->input->printing);
}
