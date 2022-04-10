/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:04:33 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/03 17:47:00 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_life_circle.h"

void	skip_eat(t_philo *philo);
void	philo_get_fork(t_philo *philo, t_mutex *fork);
void	philo_eating(t_philo *philo);
void	philo_sleeping(t_philo *philo);
void	philo_thinking(t_philo *philo);

void	*philo_life_circle(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->last_eat_time = get_time_ms();
	philo->state = thinking;
	while (1)
	{
		if (philo->how_much_eat == 0 && philo->id % 2 != 0)
			skip_eat(philo);
		philo_get_fork(philo, philo->right);
		philo_get_fork(philo, philo->left);
		philo_eating(philo);
		philo_sleeping(philo);
		philo_thinking(philo);
	}
}
