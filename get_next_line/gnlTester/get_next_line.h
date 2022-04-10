#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);

char	*ft_strdup(char *buffer_part);
char	*ft_strdup_before_slash_n(char *buffer_part);
char	*ft_strjoin(char *get_join_line_part, char *get_buffer);
char	*ft_strjoin_before_slash_n(char *get_join_line_part, char
*get_buffer);
char	*ft_strchr(char *src, int c);

#endif
