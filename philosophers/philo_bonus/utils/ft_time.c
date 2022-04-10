/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:53:10 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 01:31:20 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	get_time_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void	print_philo_time(int philo_id)
{
	ft_putnbr(get_time_ms());
	ft_putstr(" ");
	ft_putnbr(philo_id);
}

void	ms_sleep(int time_to_sleep)
{
	size_t	now;

	now = get_time_ms();
	while (now + time_to_sleep > get_time_ms())
		usleep(50);
}
