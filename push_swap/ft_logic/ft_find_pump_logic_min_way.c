#include "ft_logic.h"

int	get_steps_without_optimization(t_rotate_quantity q)
{
	return (get_min(q.ra, q.rra) + get_min(q.rb, q.rrb));
}

int	get_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	get_steps_with_rr_optimization(t_rotate_quantity q)
{
	return (get_max(q.ra, q.rb));
}

int	get_steps_with_rrr_optimization(t_rotate_quantity q)
{
	return (get_max(q.rra, q.rrb));
}

int	get_min_way_steps(t_rotate_quantity *q)
{
	int	min_way;

	min_way = get_min(get_min(get_steps_with_rr_optimization(*q),
				get_steps_with_rrr_optimization(*q)),
			get_steps_without_optimization(*q));
	if (min_way == get_steps_without_optimization(*q))
		q->opt = opt_none;
	else if (min_way == get_steps_with_rr_optimization(*q))
		q->opt = opt_rr;
	else
		q->opt = opt_rrr;
	return (min_way);
}
