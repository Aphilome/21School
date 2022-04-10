/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:00:43 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/03 14:01:36 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_parser.h"

void	argv_initializer(t_input *input, int argc, char **argv)
{
	input->number_of_philo = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		input->number_must_eat = ft_atoi(argv[5]);
	else
		input->number_must_eat = -1;
}

int	valid_checker(t_input *input, int argc)
{
	if (input->number_of_philo < 1 || input->number_of_philo >= 200
		|| input->time_to_die < 60 || input->time_to_eat < 60
		|| input->time_to_sleep < 60)
		return (0);
	if (argc == 6 && input->number_must_eat <= 0)
		return (0);
	return (1);
}

t_boolean	parse_input(t_input *input, int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
	{
		ft_putstr_error("Error: argc\n");
		return (false);
	}
	argv_initializer(input, argc, argv);
	if (!valid_checker(input, argc))
	{
		ft_putstr_error("Error: argument\n");
		return (false);
	}
	return (true);
}
