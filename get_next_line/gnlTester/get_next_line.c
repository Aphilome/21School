#include "get_next_line.h"

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

ssize_t	read_and_join_buffer(int fd, char **line, char *buffer)
{
	char		*slash_n_ptr;
	ssize_t		try_read_bytes;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	// join
	slash_n_ptr = ft_strchr(buffer, '\n');
	if (slash_n_ptr == NULL)
		return (0);
	*slash_n_ptr = '.';
	slash_n_ptr++;
	if (slash_n_ptr == NULL)
		return (0);
	*line = ft_strdup_before_slash_n(slash_n_ptr);
	if (*line == NULL)
		return (-1);
	// read
	try_read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (try_read_bytes == -1)
		return (-1);
	buffer[try_read_bytes] = 0;
	return (0);
}

int	ft_read_and_b_roll_buffer(int fd, char **line, char *buffer)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		free (*line);
		return (-1);
	}
	else if (read_bytes == 0)
		return (0);
	buffer[read_bytes] = 0;
	while (ft_strchr(buffer, '\n') != NULL);
	ft_strchr(buffer, '\n');
	/**/return (1);
}

int get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		r_j_b_res;
	char 		*tmp_buf;

	r_j_b_res = read_and_join_buffer(fd, line, buffer);
	if (r_j_b_res == -1)
		return (-1);
	if (ft_strchr(buffer, '\n') != NULL)
	{
		/* return(gnl_res =) */
		while (ft_strchr(buffer, '\n') != NULL)
		{
			tmp_buf = ft_strjoin(*line, buffer);
			if (*line != NULL)
				free(*line);
			if (tmp_buf == NULL)
				return (-1);
			*line = tmp_buf;
			ft_read_and_b_roll_buffer(fd, line, buffer);

		}
	}
	/*return(gnl_res =) */
	tmp_buf = ft_strjoin_before_slash_n(*line, buffer /*до слэш н надо склеить*/);
	free(*line);
	*line = tmp_buf;
	return (1);
}