#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (*str++ != 0)
		count++;
	return (count);
}

char	*ft_strdup(char *buffer_part)
{
	size_t	buffer_part_len;
	char	*line_part_mas;
	size_t	i;

	if (buffer_part == NULL)
		return (NULL);
	buffer_part_len = ft_strlen(buffer_part);
	line_part_mas = malloc(sizeof(char) * (buffer_part_len + 1));
	if (line_part_mas == NULL)
		return (NULL);
	i = 0;
	while (i < buffer_part_len)
	{
		line_part_mas[i] = buffer_part[i];
		i++;
	}
	line_part_mas[i] = 0;
	return (line_part_mas);
}

char	*ft_strdup_slash_n(char *buffer_part)
{
	size_t	buffer_part_len;
	char	*line_part_mas;
	size_t	i;

	if (buffer_part == NULL)
		return (NULL);
	buffer_part_len = 0;
	while (buffer_part[buffer_part_len] != 0 && buffer_part[buffer_part_len]
		!= '\n')
		buffer_part_len++;
	line_part_mas = malloc(sizeof(char) * (buffer_part_len + 1));
	if (line_part_mas == NULL)
		return (NULL);
	i = 0;
	while (i < buffer_part_len)
	{
		line_part_mas[i] = buffer_part[i];
		i++;
	}
	line_part_mas[i] = 0;
	return (line_part_mas);
}

char	*ft_strjoin_before_slash_n(char *line_join, char
*get_buffer)
{
	char	*tmp;
	char	*result_buf_ptr;

	if (line_join == NULL)
		return (ft_strdup_slash_n(get_buffer));
	if (get_buffer == NULL)
		return (ft_strdup_slash_n(line_join));
	tmp = malloc(ft_strlen(line_join) + ft_strlen_slash_n(get_buffer) + 1);
	if (tmp == NULL)
		return (NULL);
	result_buf_ptr = tmp;
	while (*line_join != 0)
	{
		*tmp = *line_join;
		line_join++;
		tmp++;
	}
	while (*get_buffer != 0 && *get_buffer != '\n')
	{
		*tmp = *get_buffer;
		get_buffer++;
		tmp++;
	}
	*tmp = 0;
	return (result_buf_ptr);
}

char	*ft_strjoin(char *get_join_line_part, char *get_buffer)
{
	char	*tmp;
	char	*result_buf_ptr;

	if (get_join_line_part == NULL)
		return (ft_strdup(get_buffer));
	if (get_buffer == NULL)
		return (ft_strdup(get_join_line_part));
	tmp = malloc(ft_strlen(get_join_line_part) + ft_strlen(get_buffer) + 1);
	if (tmp == NULL)
		return (NULL);
	result_buf_ptr = tmp;
	while (*get_join_line_part != 0)
	{
		*tmp = *get_join_line_part;
		get_join_line_part++;
		tmp++;
	}
	while (*get_buffer != 0 && *get_buffer != '\n')
	{
		*tmp = *get_buffer;
		get_buffer++;
		tmp++;
	}
	*tmp = 0;
	return (result_buf_ptr);
}
