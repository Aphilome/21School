#ifndef FT_LOGIC_H
# define FT_LOGIC_H

# include "../ft_utils/ft_utils.h"
# include "../ft_commands/ft_commands.h"
# include "../ft_utils/ft_utils.h"

void		find_longest_ascending_order(int **array_a, int length);
void		pump_everything_false_into_b(int **array_a, int **array_b,
				int length);
t_boolean	at_least_one_flag_is_false(int **array_a, int length);
int			get_min(int a, int b);
int			get_steps_without_optimization(t_rotate_quantity q);
int			get_min_way_steps(t_rotate_quantity *q);
void		ft_go_way_without_optimization(int **array_a, int **array_b,
				int length, t_rotate_quantity q);
void		ft_go_way_with_rr_optimization(int **array_a, int **array_b,
				int length, t_rotate_quantity q);
void		ft_go_way_with_rrr_optimization(int **array_a, int **array_b,
				int length, t_rotate_quantity q);
void		do_rotate_in_a(int **array_a, int length);
void		ft_sort_three_elements(int **array_a, int length);
void		ft_sort_five_elements(int **array_a, int **array_b, int length);
void		ft_if_argc_one_or_two(int *argc, char ***argv, t_boolean
				*need_clear);
void		ft_main_logic(int argc, int **mas_a, int *sort_copy_a, int
				**mas_b);

#endif
