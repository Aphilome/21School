/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:02:31 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 00:48:54 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "initializer.h"

t_boolean	forks_philo_init(t_input *input, t_philo **philo,
	t_semaphore **forks)
{
	*forks = forks_initializer(input);
	if (*forks == NULL)
	{
		ft_putstr_error("Error: semaphore creating\n");
		return (false);
	}
	*philo = philos_initializer(input, *forks);
	if (*philo == NULL)
	{
		ft_putstr_error("Error: malloc");
		return (false);
	}
	return (true);
}

t_philo	*philos_initializer(t_input *input, t_semaphore *semaphore)
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
		philo[i].pid = -1;
		philo[i].forks = semaphore;
		i++;
	}
	return (philo);
}

t_semaphore	*forks_initializer(t_input *input)
{
	t_semaphore	*forks;
	int			i;

	sem_unlink("forks");
	forks = sem_open("forks", O_CREAT, 666, input->number_of_philo);
	if (forks == SEM_FAILED)
		return (NULL);
	sem_unlink("printing");
	input->printing = sem_open("printing", O_CREAT, 666, 1);
	if (input->printing == SEM_FAILED)
		return (NULL);
	sem_unlink("overlap");
	input->overlap = sem_open("overlap", O_CREAT, 666, input->number_of_philo);
	if (input->overlap == SEM_FAILED)
		return (NULL);
	i = 0;
	while (i < input->number_of_philo)
	{
		sem_wait(input->overlap);
		i++;
	}
	return (forks);
}
