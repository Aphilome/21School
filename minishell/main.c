/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbirdper <tbirdper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:34:34 by aphilome          #+#    #+#             */
/*   Updated: 2021/11/13 19:53:19 by tbirdper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser/parser.h"
#include "readline_logic/readline_logic.h"
#include "utils/utils.h"
#include "commands/commands.h"
#include "signals/signals.h"

int	g_e_bash_errno = 0;

t_env_list	*init(int argc, char **argv, char **environment)
{
	(void) argc;
	(void) argv;
	rl_outstream = stderr;
	signals_on();
	return (create_environment(environment));
}

t_bool	input_is_null(char *input)
{
	if (input == NULL)
	{
		ft_print_error("\e[1A\e[8C" "exit\n");
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv, char **environment)
{
	t_cmd		**cmds;
	t_env_list	*env;
	char		*input;

	env = init(argc, argv, environment);
	while (errno == 0)
	{
		is_system_error();
		input = read_cmd();
		if (input_is_null(input))
			return (g_e_bash_errno);
		if (is_empty(input))
		{
			try_free(input);
			continue ;
		}
		add_history(input);
		cmds = create_commands(input, env);
		try_free(input);
		if (cmds == NULL)
			continue ;
		run_commands(cmds, &env);
		clear_cmds(cmds);
		cmds = NULL;
	}
}
