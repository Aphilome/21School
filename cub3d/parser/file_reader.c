#include "parser_private.h"

void	need_close_and_exit(t_bool condition, int fd, char *msg)
{
	if (condition)
	{
		close(fd);
		error_exit(msg);
	}
}

t_list	*read_all_file(char *file_name)
{
	int			fd;
	char		*line;
	t_ret_code	code;
	t_list		*head;
	t_list		*lst_element;

	line = NULL;
	head = NULL;
	fd = open(file_name, O_RDONLY);
	code = get_next_line(fd, &line);
	while (code == code_readline || (code == code_eof && line != NULL))
	{
		lst_element = ft_lstnew(line);
		need_close_and_exit(lst_element == NULL, fd, ERROR_MALLOC);
		ft_lstadd_back(&head, lst_element);
		if (code == code_eof)
			break ;
		code = get_next_line(fd, &line);
	}
	need_close_and_exit(code == code_error, fd, ERROR_MALLOC);
	if (close(fd) == -1)
		error_exit(ERROR_SYSTEM);
	return (head);
}
