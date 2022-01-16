#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>
# include <stdlib.h>

typedef enum e_standart_input_output
{
	standart_input = 0,
	standart_output = 1,
	standart_error = 2
}	t_standart_input_output;

typedef enum e_array_params
{
	order = 0,
	flag = 1,
	value = 2,
	exist = 3
}	t_array_params;

typedef enum e_boolean
{
	false = 0,
	true = 1
}	t_boolean;

typedef enum e_opt_flag
{
	opt_none,
	opt_rr,
	opt_rrr
}	t_opt_flag;

typedef struct s_rotate_quantity
{
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	int			rr;
	int			rrr;
	t_opt_flag	opt;
}	t_rotate_quantity;

void		ft_putstr_std_error(char *s);
void		ft_putstr_std_output(char *s);

t_boolean	try_get_itoa(char *s, int *res);

t_boolean	check_and_fill_array(int **mas, int length, char **argv);
void		set_params(int length, int *sort_copy_array, int **array,
				int need);
int			get_actual_length(int **array, int length);
t_boolean	is_sorted(int **array, int length);
void		ft_pump_sequence_logic_into_a(int **array_a, int **array_b,
				int length);

void		fill_array_param(int length, int *array, int **src_array,
				t_array_params param);
void		sort_array(int length, int *array);
t_boolean	ft_check_duplicates(const int *sorted_array, int length);
char		**ft_split(char const *s, char c);
int			get_array_length(char **argv);
t_boolean	init_mas(int ***mas_a, int **sort_copy_a, int ***mas_b, int length);
void		free_mas(int ***mas_a, int **sort_copy_a, int ***mas_b, int length);
void		print_exit(char **clear_argv);
void		clear_argv(char **argv);

#endif
