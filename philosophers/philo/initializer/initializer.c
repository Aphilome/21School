/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:02:31 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/03 14:02:59 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

void	philo_set_forks(t_philo *philo, t_mutex *forks)
{
	int	r;
	int	l;

	if (philo->id == 0)
		l = philo->input->number_of_philo - 1;
	else
		l = philo->id - 1;
	r = philo->id;
	philo->right = &forks[r];
	philo->left = &forks[l];
}

t_philo	*philos_initializer(t_input *input, t_mutex *forks, t_mutex *printing)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * input->number_of_philo);
	if (philo == NULL)
		return (NULL);
	i = 0;
	while (i < input->number_of_philo)
	{
		philo[i].id = i;
		philo[i].state = init;
		philo[i].how_much_eat = 0;
		philo[i].input = input;
		philo[i].printing = printing;
		philo_set_forks(&philo[i], forks);
		i++;
	}
	return (philo);
}

t_mutex	*forks_initializer(int number_of_philo)
{
	int		i;
	t_mutex	*forks;

	forks = malloc(sizeof(t_mutex) * number_of_philo);
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}
