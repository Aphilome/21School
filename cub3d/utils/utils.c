#include "utils.h"

int ft_strlen(char *msg)
{
	int i;

	i = 0;
	while (msg[i] != 0)
		i++;
	return (i);
}

void error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}

void print_strl(char *msg)
{
	print_str(msg);
	print_str("\n");
}

void print_str(char *msg)
{
	write(1, msg, ft_strlen(msg));
}


char	*ft_substr(char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	if (len == 0 || s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		error_exit(ERROR_MALLOC);
	if (s_len < len || s_len < start)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_simple_atoi(char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

char	*trim(char *str)
{
	char	*res;
	size_t	left;
	size_t	right;

	if (str == NULL)
		return (NULL);
	right = ft_strlen(str);
	left = 0;
	while (left < right && str[left] == ' ')
		left++;
	if (left == right)
		return (NULL);
	while (right > left && str[right - 1] == ' ')
		right--;
	res = ft_substr(str, left, right - left);
	return (res);
}

// индекс, на котором строки начали отличаться. -1 если не одинаковые
int start_with(char *str, char *sub_str)
{
	int i;

	i = 0;
	if (str == NULL || sub_str == NULL || ft_strlen(str) < ft_strlen(sub_str))
		return (-1);
	while (sub_str[i] != 0 && str[i] == sub_str[i])
		i++;
	if (sub_str[i] != 0)
		return (-1);
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*dst;
	size_t	len;

	if (src == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(src);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		error_exit(ERROR_MALLOC);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}