/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphilome <aphilome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:36:35 by aphilome          #+#    #+#             */
/*   Updated: 2021/10/31 17:36:36 by aphilome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_export.h"

char	**sorted_env(t_env_list *env)
{
	size_t	i;
	char	*tmp;
	t_bool	is_swap;
	char	**mas;

	mas = get_flat_env(env, true);
	is_swap = true;
	while (is_swap)
	{
		is_swap = false;
		i = 0;
		while (mas[i + 1] != NULL)
		{
			if (ft_strcmp(mas[i], mas[i + 1]) > 0)
			{
				tmp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = tmp;
				is_swap = true;
			}
			i++;
		}
	}
	return (mas);
}
