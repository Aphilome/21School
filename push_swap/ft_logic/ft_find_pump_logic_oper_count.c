#include "ft_logic.h"

int	ft_find_need_ra_count(int **array_a, int **array_b, int length, int
col)
{
	int	big_index;
	int	small_index;
	int	ra_count;

	small_index = get_actual_length(array_a, length) - 1;
	big_index = 0;
	if (is_sorted(array_a, length) == true)
	{
		if ((array_b[col][order] > array_a[small_index][order])
			|| (array_b[col][order] < array_a[big_index][order]))
			return (0);
	}
	ra_count = 0;
	while (!(array_b[col][order] < array_a[big_index][order]
	&& array_b[col][order] > array_a[small_index][order]))
	{
		if (array_a[small_index][order] > array_a[big_index][order]
			&& (array_b[col][order] > array_a[small_index][order] ||
			array_b[col][order] < array_a[big_index][order]))
			return (ra_count);
		small_index = big_index;
		big_index = small_index + 1;
		ra_count++;
	}
	return (ra_count);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_rotate_quantity	get_steps_quantity(int **array_a, int **array_b,
									 int length, int col)
{
	t_rotate_quantity	q;
	int					b_length;
	int					a_length;

	b_length = get_actual_length(array_b, length);
	a_length = get_actual_length(array_a, length);
	q.rb = col;
	if (b_length == 1)
		q.rrb = 0;
	else
		q.rrb = get_actual_length(array_b, length) - q.rb;
	q.ra = ft_find_need_ra_count(array_a, array_b, length, col);
	if (a_length == 1)
		q.rra = 0;
	else
		q.rra = get_actual_length(array_a, length) - q.ra;
	q.rr = get_min(q.ra, q.rb);
	q.rrr = get_min(q.rra, q.rrb);
	return (q);
}

t_rotate_quantity	ft_find_min_way_value(int **array_a, int **array_b,
										int length)
{
	int					i;
	t_rotate_quantity	current;
	t_rotate_quantity	min;
	t_boolean			empty_min;

	empty_min = true;
	i = 0;
	while (i < length && array_b[i][exist] == true)
	{
		current = get_steps_quantity(array_a, array_b, length, i);
		if (empty_min == true || get_min_way_steps(&current)
			< get_min_way_steps(&min))
		{
			min = current;
			get_min_way_steps(&min);
			empty_min = false;
		}
		i++;
	}
	return (min);
}

void	ft_pump_sequence_logic_into_a(int **array_a, int **array_b,
									  int length)
{
	t_rotate_quantity	min_way_value;

	while (array_b[0][exist] == true)
	{
		min_way_value = ft_find_min_way_value(array_a, array_b, length);
		if (min_way_value.opt == opt_none)
			ft_go_way_without_optimization(array_a, array_b, length,
				min_way_value);
		else if (min_way_value.opt == opt_rr)
			ft_go_way_with_rr_optimization(array_a, array_b, length,
				min_way_value);
		else
			ft_go_way_with_rrr_optimization(array_a, array_b, length,
				min_way_value);
		push_a(array_a, array_b, length, true);
	}
}
