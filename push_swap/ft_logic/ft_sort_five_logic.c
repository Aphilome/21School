#include "ft_logic.h"

void	ft_sort_five_elements(int **array_a, int **array_b, int length)
{
	if (is_sorted(array_a, length) == true)
		return ;
	push_b(array_a, array_b, length, true);
	push_b(array_a, array_b, length, true);
	ft_sort_three_elements(array_a, length);
	ft_pump_sequence_logic_into_a(array_a, array_b, length);
	do_rotate_in_a(array_a, length);
}
