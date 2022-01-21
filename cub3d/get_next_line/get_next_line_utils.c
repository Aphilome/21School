#include "get_next_line.h"

char		*ft_get_sn(const char *s);
t_ret_code	try_free(char **line);
char		*get_old_buf(char *buf);
char		*ft_strjoin_sn(char const *res, char const *buf);
t_ull		ft_strlen_sn(const char *str);

t_ret_code	init(int fd, char **line, char	*buf)
{
	ssize_t	fact_bytes;

	if (BUFFER_SIZE < 1 || fd < 0 || line == NULL)
		return (code_error);
	*line = get_old_buf(buf);
	if (*line != NULL)
	{
		*line = ft_strjoin_sn(*line, NULL);
		if (*line == NULL)
			return (code_error);
		if (ft_get_sn(buf) != NULL)
			return (code_readline);
	}
	fact_bytes = read(fd, buf, BUFFER_SIZE);
	if (fact_bytes < 0)
		return (try_free(line));
	buf[fact_bytes] = '\0';
	return (code_ok);
}

char	*ft_strdup_sn(const char *src)
{
	t_ull	i;
	char	*dst;
	t_ull	len;

	i = 0;
	len = ft_strlen_sn(src);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

t_ret_code	read_buf_from_file(int fd, char **line, char *buf)
{
	char		*tmp_str;
	ssize_t		fact_bytes;

	tmp_str = ft_strjoin_sn(*line, buf);
	try_free(line);
	if (tmp_str == NULL)
		return (code_error);
	*line = tmp_str;
	fact_bytes = read(fd, buf, BUFFER_SIZE);
	if (fact_bytes == 0)
		return (code_eof);
	else if (fact_bytes < 0)
		return (try_free(line));
	buf[fact_bytes] = '\0';
	return (code_ok);
}

char	*get_old_buf(char *buf)
{
	char	*sn;

	sn = ft_get_sn(buf);
	if (sn == NULL)
		return (NULL);
	*sn = '_';
	sn++;
	if (*sn == 0)
		return (NULL);
	return (sn);
}

char	*ft_strjoin_sn(char const *res, char const *buf)
{
	char	*base;
	t_ull	i_dst;
	t_ull	i_src;

	i_dst = 0;
	if (res == NULL)
		return (ft_strdup_sn(buf));
	if (buf == NULL)
		return (ft_strdup_sn(res));
	base = malloc(ft_strlen_sn(res) + ft_strlen_sn(buf) + 1);
	if (base == NULL)
		return (NULL);
	i_src = 0;
	while (!(res[i_src] == 0 || res[i_src] == '\n'))
		base[i_dst++] = res[i_src++];
	i_src = 0;
	while (!(buf[i_src] == 0 || buf[i_src] == '\n'))
		base[i_dst++] = buf[i_src++];
	base[i_dst] = 0;
	return (base);
}
