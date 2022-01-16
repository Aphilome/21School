#include <stdlib.h>
#include "ft_utils/ft_utils.h"
#include "ft_logic/ft_logic.h"
#include "ft_checker_bonus/ft_checker_bonus.h"

void	ft_check_input(int argc, t_boolean *need_clear)
{
	if (argc <= 1)
	{
		ft_putstr_std_output("You need to inter values\n");
		exit (0);
	}
	*need_clear = false;
}

void	ft_check_exit(char ***argv, t_boolean *need_clear)
{
	if (*need_clear == true)
		print_exit(*argv);
	else
		print_exit(NULL);
}

void	ft_print_msgs(int **mas_a, int **mas_b, int length)
{
	if (ft_read_execution(mas_a, mas_b, length) == false)
		ft_putstr_std_error("Error\n");
	else
	{
		if (is_sorted(mas_a, length) == true && mas_b[0][exist] == false)
			ft_putstr_std_output("OK\n");
		else
			ft_putstr_std_output("KO\n");
	}
}

int	main(int argc, char **argv)
{
	int			**mas_a;
	int			*sort_copy_a;
	int			**mas_b;
	t_boolean	need_clear;

	ft_check_input(argc, &need_clear);
	ft_if_argc_one_or_two(&argc, &argv, &need_clear);
	if (init_mas(&mas_a, &sort_copy_a, &mas_b, argc - 1) == false)
		print_exit(argv);
	if (check_and_fill_array(mas_a, argc - 1, argv) == false
		|| check_and_fill_array(mas_b, argc - 1, argv) == false)
	{
		free_mas(&mas_a, &sort_copy_a, &mas_b, argc - 1);
		ft_check_exit(&argv, &need_clear);
	}
	if (need_clear == true)
		clear_argv(argv);
	fill_array_param(argc - 1, sort_copy_a, mas_a, value);
	sort_array(argc - 1, sort_copy_a);
	if (ft_check_duplicates(sort_copy_a, argc - 1) == true)
		print_exit(NULL);
	set_params(argc - 1, sort_copy_a, mas_a, 1);
	set_params(argc - 1, sort_copy_a, mas_b, 0);
	ft_print_msgs(mas_a, mas_b, argc - 1);
	free_mas(&mas_a, &sort_copy_a, &mas_b, argc - 1);
}
