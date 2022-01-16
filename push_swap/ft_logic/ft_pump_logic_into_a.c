#include "ft_logic.h"

void	ft_go_way_without_optimization(int **array_a, int **array_b,
								   int length, t_rotate_quantity q)
{
	if (q.ra < q.rra)
		rotate_a_count(array_a, length, q.ra);
	else
		reverse_rotate_a_count(array_a, length, q.rra);
	if (q.rb < q.rrb)
		rotate_b_count(array_b, length, q.rb);
	else
		reverse_rotate_b_count(array_b, length, q.rrb);
}

void	ft_go_way_with_rr_optimization(int **array_a, int **array_b,
									int length, t_rotate_quantity q)
{
	while (q.rr > 0)
	{
		rotate_ab(array_a, array_b, length, true);
		q.rr--;
		q.ra--;
		q.rb--;
	}
	rotate_a_count(array_a, length, q.ra);
	rotate_b_count(array_b, length, q.rb);
}

void	ft_go_way_with_rrr_optimization(int **array_a, int **array_b,
									int length, t_rotate_quantity q)
{
	while (q.rrr > 0)
	{
		reverse_rotate_ab(array_a, array_b, length, true);
		q.rrr--;
		q.rra--;
		q.rrb--;
	}
	reverse_rotate_a_count(array_a, length, q.rra);
	reverse_rotate_b_count(array_b, length, q.rrb);
}
