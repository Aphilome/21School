#ifndef FT_COMMANDS_H
# define FT_COMMANDS_H

# include "../ft_utils/ft_utils.h"

void	change_param_setter(int **array, t_array_params param, int
			need, int col);

void	move_array_elements(int **array, int col1, int col2);
void	shift_all_mas_elem_left(int **array, int col);
void	shift_all_mas_elem_right(int **array, int col);

void	push_a(int **array_a, int **array_b, int length, t_boolean need_print);
void	push_b(int **array_a, int **array_b, int length, t_boolean need_print);

void	swap_a(int **array_a, t_boolean need_print);
void	swap_b(int **array_b, t_boolean need_print);
void	swap_s(int **array_a, int **array_b, t_boolean need_print);

void	rotate_a(int **array_a, int length, t_boolean need_print);
void	rotate_b(int **array_b, int length, t_boolean need_print);
void	rotate_ab(int **array_a, int **array_b, int length,
			t_boolean need_print);

void	reverse_rotate_a(int **array_a, int length, t_boolean need_print);
void	reverse_rotate_b(int **array_b, int length, t_boolean need_print);
void	reverse_rotate_ab(int **array_a, int **array_b, int length,
			t_boolean need_print);

void	rotate_a_count(int **array_a, int length, int count);
void	rotate_b_count(int **array_a, int length, int count);
void	reverse_rotate_a_count(int **array_a, int length, int count);
void	reverse_rotate_b_count(int **array_a, int length, int count);

#endif
