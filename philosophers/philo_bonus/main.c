/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:13:49 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 01:30:49 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <signal.h>
#include "utils/utils.h"
#include "philo_data/philo_data.h"
#include "data_parser/data_parser.h"
#include "philo_life_circle/philo_life_circle.h"
#include "initializer/initializer.h"

void	start_philo_caretaker(t_philo	*philo)
{
	int	th_create_res;

	th_create_res = pthread_create(&philo->monitor_thread,
			NULL, caretaker_life_circle, philo);
	if (th_create_res != 0)
		exit(exit_sys_error);
}

void	killer(t_philo	*philo)
{
	int	i;
	int	number_of_philo;

	i = 0;
	number_of_philo = philo[0].input->number_of_philo;
	while (i < number_of_philo)
	{
		if (philo[i].pid != -1)
			kill(philo[i].pid, SIGKILL);
		i++;
	}
}

t_boolean	start_philo(t_philo	*philo)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < philo[0].input->number_of_philo)
	{
		pid = fork();
		if (pid < 0)
		{
			killer(philo);
			return (false);
		}
		if (pid == 0)
		{
			start_philo_caretaker(&philo[i]);
			sem_wait(philo[i].input->overlap);
			ms_sleep(100);
			philo_life_circle(&philo[i]);
		}
		else
			philo[i].pid = pid;
		i++;
	}
	return (true);
}

int	monitoring(t_input	*input, t_philo	*philo)
{
	int			i;
	int			status;

	i = 0;
	while (i < input->number_of_philo)
	{
		wait(&status);
		status /= 256;
		if (status == exit_philo_died)
		{
			killer(philo);
			return (1);
		}
		if (status == exit_sys_error)
		{
			killer(philo);
			return (2);
		}
		if (status == exit_philo_done)
		{
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_input		input;
	t_philo		*philo;
	t_semaphore	*forks;
	int			i;

	if (!parse_input(&input, argc, argv))
		return (1);
	if (!forks_philo_init(&input, &philo, &forks))
		return (1);
	if (!start_philo(philo))
	{
		ft_putstr_error("Error: process creating");
		return (1);
	}
	i = 0;
	while (i < input.number_of_philo)
	{
		sem_post(input.overlap);
		i++;
	}
	return (monitoring(&input, philo));
}
