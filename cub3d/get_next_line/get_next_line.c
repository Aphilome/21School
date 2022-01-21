#include "get_next_line.h"

char		*ft_strjoin_sn(char const *res, char const *buf);
t_ret_code	read_buf_from_file(int fd, char **line, char *buf);
t_ret_code	init(int fd, char **line, char	*buf);

t_ret_code	try_free(char **line)
{
	if (*line != NULL)
		free(*line);
	return (code_error);
}

t_ull	ft_strlen_sn(const char *str)
{
	t_ull	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_get_sn(const char *s)
{
	while (*s != 0)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*tmp_str;
	t_ret_code	func_res;

	func_res = init(fd, line, buf);
	if (func_res != code_ok)
		return (func_res);
	while (ft_get_sn(buf) == NULL)
	{
		func_res = read_buf_from_file(fd, line, buf);
		if (func_res != code_ok)
			return (func_res);
	}
	tmp_str = ft_strjoin_sn(*line, buf);
	try_free(line);
	if (tmp_str == NULL)
		return (code_error);
	*line = tmp_str;
	return (code_readline);
}
