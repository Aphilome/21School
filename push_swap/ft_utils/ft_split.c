#include "ft_utils.h"

static size_t	ft_part_len(const char *str, char separator)
{
	size_t	len;

	len = 0;
	while (*(str + len) != 0 && *(str + len) != separator)
		len++;
	return (len);
}

static char	*ft_part_dup(const char *src, char separator)
{
	size_t	i;
	char	*dst;
	size_t	len;

	i = 0;
	len = ft_part_len(src, separator);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = 0;
	return (dst);
}

static size_t	ft_get_rows_count(const char *str, char separator)
{
	size_t	count;
	int		status;

	count = 0;
	status = 0;
	while (*str != 0)
	{
		if (status == 0)
		{
			if (*str != separator)
			{
				count++;
				status = 1;
			}
		}
		else if (*str == separator)
			status = 0;
		str++;
	}
	return (count);
}

static char	**ft_clear(char **mas, int i)
{
	while (i >= 0)
		free(mas[i--]);
	free(mas);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**mas;
	size_t	count;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = ft_get_rows_count(s, c);
	mas = malloc(sizeof(char *) * (count + 1));
	if (mas == NULL)
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		mas[i] = ft_part_dup(s, c);
		if (mas[i] == NULL)
			return (ft_clear(mas, i - 1));
		s += ft_part_len(s, c);
		i++;
	}
	mas[i] = NULL;
	return (mas);
}
