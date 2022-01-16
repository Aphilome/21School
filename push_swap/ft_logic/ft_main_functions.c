#include "ft_logic.h"

void	ft_if_argc_one_or_two(int *argc, char ***argv, t_boolean *need_clear)
{
	if (*argc == 1)
	{
		ft_putstr_std_output("You need to inter values\n");
		exit(0);
	}
	if (*argc == 2)
	{
		*argv = ft_split((*argv)[1], ' ');
		if (*argv == NULL)
			print_exit(NULL);
		*need_clear = true;
		*argc = get_array_length(*argv) + 1;
	}
	else
		*argv = &((*argv)[1]);
}

void	ft_main_logic(int argc, int **mas_a, int *sort_copy_a, int	**mas_b)
{
	if (argc - 1 <= 3)
		ft_sort_three_elements(mas_a, argc - 1);
	else if (argc - 1 == 5)
		ft_sort_five_elements(mas_a, mas_b, argc - 1);
	else
	{
		find_longest_ascending_order(mas_a, argc - 1);
		pump_everything_false_into_b(mas_a, mas_b, argc - 1);
		ft_pump_sequence_logic_into_a(mas_a, mas_b, argc - 1);
		do_rotate_in_a(mas_a, argc - 1);
	}
	free_mas(&mas_a, &sort_copy_a, &mas_b, argc - 1);
}
