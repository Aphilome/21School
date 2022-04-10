/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:13:18 by aphilome          #+#    #+#             */
/*   Updated: 2021/12/05 01:31:03 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <sys/time.h>

typedef enum e_boolean
{
	false = 0,
	true = 1
}	t_boolean;

void	ft_putstr_error(char *str);
int		ft_atoi(const char *str);
size_t	get_time_ms(void);
void	ms_sleep(int time_to_sleep);
void	ft_putnbr(size_t n);
void	ft_putstr(char *str);
void	print_philo_time(int philo_id);

#endif
