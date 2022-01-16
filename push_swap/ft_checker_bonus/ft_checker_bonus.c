#include "ft_checker_bonus.h"

t_boolean	ft_t_boolean_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (i >= 0)
	{
		if (*(s1 + i) == 0 && *(s2 + i) == 0)
			return (true);
		else if (*(s1 + i) == 0 || *(s2 + i) == 0)
			return (false);
		else
		{
			if (*(s1 + i) > *(s2 + i) || *(s1 + i) < *(s2 + i))
				return (false);
		}
		i++;
	}
	return (true);
}

t_boolean	try_execute_command(int **mas_a, int **mas_b, int length, char *s)
{
	if (ft_t_boolean_strcmp(s, "sa") == true)
		swap_a(mas_a, false);
	else if (ft_t_boolean_strcmp(s, "sb") == true)
		swap_b(mas_b, false);
	else if (ft_t_boolean_strcmp(s, "ss") == true)
		swap_s(mas_a, mas_b, false);
	else if (ft_t_boolean_strcmp(s, "pa") == true)
		push_a(mas_a, mas_b, length, false);
	else if (ft_t_boolean_strcmp(s, "pb") == true)
		push_b(mas_a, mas_b, length, false);
	else if (ft_t_boolean_strcmp(s, "ra") == true)
		rotate_a(mas_a, length, false);
	else if (ft_t_boolean_strcmp(s, "rb") == true)
		rotate_b(mas_b, length, false);
	else if (ft_t_boolean_strcmp(s, "rr") == true)
		rotate_ab(mas_a, mas_b, length, false);
	else if (ft_t_boolean_strcmp(s, "rra") == true)
		reverse_rotate_a(mas_a, length, false);
	else if (ft_t_boolean_strcmp(s, "rrb") == true)
		reverse_rotate_b(mas_b, length, false);
	else if (ft_t_boolean_strcmp(s, "rrr") == true)
		reverse_rotate_ab(mas_a, mas_b, length, false);
	else
		return (false);
	return (true);
}

t_boolean	ft_read_execution(int **mas_a, int **mas_b, int length)
{
	int		gnl_result;
	char	*s;

	s = NULL;
	gnl_result = get_next_line(0, &s);
	while (gnl_result == 1)
	{
		if (try_execute_command(mas_a, mas_b, length, s) == false)
		{
			free(s);
			return (false);
		}
		free(s);
		gnl_result = get_next_line(0, &s);
	}
	if (s != NULL)
		free(s);
	if (gnl_result == -1)
		return (false);
	return (true);
}
