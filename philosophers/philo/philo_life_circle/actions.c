/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:41:43 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 01:25:59 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_life_circle.h"
#include "../utils/utils.h"

void	skip_eat(t_philo *philo)
{
	ms_sleep(philo->input->time_to_eat);
}

void	philo_get_fork(t_philo *philo, t_mutex *fork)
{
	philo->state = has_taken_a_fork;
	pthread_mutex_lock(fork);
	pthread_mutex_lock(philo->printing);
	print_philo_time(philo->id);
	ft_putstr(" has taken a fork\n");
	pthread_mutex_unlock(philo->printing);
}

void	philo_eating(t_philo *philo)
{
	philo->last_eat_time = get_time_ms();
	philo->state = eating;
	pthread_mutex_lock(philo->printing);
	print_philo_time(philo->id);
	ft_putstr(" is eating\n");
	pthread_mutex_unlock(philo->printing);
	ms_sleep(philo->input->time_to_eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	philo_sleeping(t_philo *philo)
{
	philo->state = sleeping;
	pthread_mutex_lock(philo->printing);
	print_philo_time(philo->id);
	ft_putstr(" is sleeping\n");
	pthread_mutex_unlock(philo->printing);
	philo->how_much_eat++;
	ms_sleep(philo->input->time_to_sleep);
}

void	philo_thinking(t_philo *philo)
{
	philo->state = thinking;
	pthread_mutex_lock(philo->printing);
	print_philo_time(philo->id);
	ft_putstr(" is thinking\n");
	pthread_mutex_unlock(philo->printing);
}
