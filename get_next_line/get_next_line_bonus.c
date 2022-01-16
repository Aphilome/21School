#include "get_next_line_bonus.h"

char	*ft_strchr(char *src, int c)
{
	char	*ptr;

	ptr = src;
	while (*ptr != 0)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

size_t	ft_strlen_slash_n(char *str)
{
	size_t	count;

	count = 0;
	while (*str != 0 && *str != '\n')
	{
		str++;
		count++;
	}
	return (count);
}

int	ft_subsequent_round(int fd, char buffer[FD_SIZE][BUFFER_SIZE + 1], char
**line)
{
	char	*tmp;
	char	*tmp_line;
	ssize_t	try_read_bytes;

	tmp_line = ft_strchr(buffer[fd], '\n');
	if (tmp_line != NULL)
	{
		*tmp_line = '.';
		tmp_line += 1;
		tmp = *line;
		*line = ft_strdup_slash_n(tmp_line);
		free(tmp);
		if (*line == NULL)
			return (-1);
	}
	if (ft_strchr(buffer[fd], '\n') != NULL)
		return (1);
	try_read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
	if (try_read_bytes == -1)
	{
		free (*line);
		return (-1);
	}
	buffer[fd][try_read_bytes] = 0;
	return (0);
}

int	ft_have_right_part(int fd, char buffer[FD_SIZE][BUFFER_SIZE + 1], char
**line)
{
	int			have_right_part;
	ssize_t		read_bytes;
	char		*tmp;

	have_right_part = ft_strchr(buffer[fd], '\n') != NULL;
	while (have_right_part == 0)
	{
		tmp = ft_strjoin(*line, buffer[fd]);
		free(*line);
		if (tmp == NULL)
			return (-1);
		*line = tmp;
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (*line);
			return (-1);
		}
		else if (read_bytes == 0)
			return (0);
		buffer[fd][read_bytes] = 0;
		have_right_part = ft_strchr(buffer[fd], '\n') != NULL;
	}
	return (42);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[FD_SIZE][BUFFER_SIZE + 1];
	int			status;
	char		*tmp;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL || read(fd, 0, 0) < 0)
		return (-1);
	*line = ft_strdup("");
	if (*line == NULL)
		return (-1);
	if (*(buffer[fd]) != '\0')
	{
		status = ft_subsequent_round(fd, buffer, line);
		if (status != 0)
			return (status);
	}
	status = ft_have_right_part(fd, buffer, line);
	if (status != 42)
		return (status);
	tmp = ft_strjoin_before_slash_n(*line, buffer[fd]);
	free(*line);
	if (tmp == NULL)
		return (-1);
	*line = tmp;
	return (1);
}
