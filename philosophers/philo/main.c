/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:13:49 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 01:29:51 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "utils/utils.h"
#include "philo_data/philo_data.h"
#include "data_parser/data_parser.h"
#include "philo_life_circle/philo_life_circle.h"
#include "initializer/initializer.h"

t_boolean	start_philo(t_philo	*philo)
{
	int	i;
	int	th_create_res;
	int	number_of_philo;

	i = 0;
	number_of_philo = philo[0].input->number_of_philo;
	while (i < number_of_philo)
	{
		th_create_res = pthread_create(&philo[i].thread, NULL,
				philo_life_circle, &philo[i]);
		if (th_create_res != 0)
			return (false);
		i++;
	}
	return (true);
}

t_boolean	forks_philo_init(t_input *input, t_philo **philo, t_mutex **forks,
	t_mutex *printing)
{
	*forks = forks_initializer(input->number_of_philo);
	if (*forks == NULL)
	{
		ft_putstr_error("Error: mutex creating\n");
		return (false);
	}
	*philo = philos_initializer(input, *forks, printing);
	if (*philo == NULL)
	{
		ft_putstr_error("Error: malloc");
		return (false);
	}
	return (true);
}

void	print_died(t_philo *philo)
{
	pthread_mutex_lock(philo->printing);
	print_philo_time(philo->id);
	ft_putstr(" died\n");
	pthread_mutex_unlock(philo->printing);
}

int	monitoring(t_input	*input, t_philo	*philo)
{
	int			i;
	t_boolean	state;

	while (1)
	{
		i = 0;
		state = false;
		while (i < input->number_of_philo)
		{
			if (philo[i].state != init
				&& get_time_ms() > philo[i].last_eat_time + input->time_to_die)
			{
				print_died(&philo[i]);
				return (1);
			}
			if (input->number_must_eat != -1
				&& philo[i].how_much_eat < input->number_must_eat)
				state = true;
			i++;
		}
		if (input->number_must_eat != -1
			&& state == false)
			return (0);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	t_input	input;
	t_philo	*philo;
	t_mutex	*forks;
	t_mutex	printing;
	int		res;

	if (!parse_input(&input, argc, argv))
		return (1);
	if (pthread_mutex_init(&printing, NULL) != 0)
		return (1);
	if (!forks_philo_init(&input, &philo, &forks, &printing))
		return (1);
	if (!start_philo(philo))
	{
		ft_putstr_error("Error: pthread creating");
		return (1);
	}
	res = monitoring(&input, philo);
	pthread_mutex_lock(philo->printing);
	return (res);
}
