#include "ft_utils.h"

t_boolean	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (false);
	return (true);
}
