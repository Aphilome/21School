/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:29:08 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 01:49:05 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*single_quotation_handler(char *input)
{
	input++;
	while (*input != 0)
	{
		if (*input == '\'')
			return (input);
		input++;
	}
	ft_print_error("Error single quotation closing!\n");
	return (NULL);
}

char	*double_quotation_handler(char *input)
{
	input++;
	while (*input != 0)
	{
		if (*input == '\"')
			return (input);
		input++;
	}
	ft_print_error("Error double quotation closing!\n");
	return (NULL);
}

t_bool	is_bordered_with_pipe(char *input)
{
	size_t	i;

	i = 0;
	while (is_space(input[i]))
		i++;
	if (input[i] == '|')
		return (true);
	i = ft_strlen(input) - 1;
	while (is_space(input[i]) && i >= 0)
		i--;
	if (i >= 0 && input[i] == '|')
		return (true);
	return (false);
}

t_bool	is_valid(char *input)
{
	while (*input != 0)
	{
		if (*input == '\'')
			input = single_quotation_handler(input);
		else if (*input == '\"')
			input = double_quotation_handler(input);
		if (input == NULL)
			return (false);
		input++;
	}
	return (true);
}
