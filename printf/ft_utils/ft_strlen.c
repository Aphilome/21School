#include "ft_utils.h"

long long	ft_strlen(char *s)
{
	long long	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
