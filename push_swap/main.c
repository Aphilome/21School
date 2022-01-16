#include <stdlib.h>
#include "ft_utils/ft_utils.h"
#include "ft_logic/ft_logic.h"

void	ft_check_exit(char ***argv, t_boolean *need_clear)
{
	if (*need_clear == true)
		print_exit(*argv);
	else
		print_exit(NULL);
}

int	main(int argc, char **argv)
{
	int			**mas_a;
	int			*sort_copy_a;
	int			**mas_b;
	t_boolean	need_clear;

	need_clear = false;
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
	ft_main_logic(argc, mas_a, sort_copy_a, mas_b);
//	while (1);
}
