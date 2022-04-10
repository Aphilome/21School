#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define FATAL_ERROR "error: fatal"

typedef enum e_boolean
{
	false = 0,
	true = 1
} t_boolean;

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != 0)
		i++;
	return(i);
}

void print_error(char *err_msg, char *path, t_boolean need_exit)
{
	write(2, err_msg, ft_strlen(err_msg));
	if (path != NULL)
		write(2, path, ft_strlen(path));
	write(2, "\n", 1);
	if (need_exit)
		exit(1);
}

void go_end(char **argv, int *i)
{
	while (argv[*i] != NULL
				&& (strcmp(argv[*i], ";") != 0)
				&& (strcmp(argv[*i], "|") != 0))
		(*i)++;
}

//      5  6    7         8             9
// ...  | cd /test/tst    hgfgkyui
void my_cd(char **argv, int *i)
{
	int start = *i;
	go_end(argv, i);
	if (start + 2 != *i)
		print_error("error: cd: bad arguments", NULL, false);
	else if (chdir(argv[start + 1]) == -1)
		print_error("error: cd: cannot change directory to ", argv[start + 1],
					false);
}

t_boolean exec(char **argv, int *i, char **env, int *previous_fd)
{
	int pipe_fd[2] = {0, 1};
	int io_fd[2] = {0, 1};

	int start = *i;
	go_end(argv, i);

	t_boolean is_pipe = argv[*i] != NULL && strcmp(argv[*i], "|") == 0;
	t_boolean is_end = argv[*i] == NULL || strcmp(argv[*i], ";") == 0;

	if(is_pipe && pipe(pipe_fd) == -1)
		print_error(FATAL_ERROR, NULL, true);

	argv[*i] = NULL;

	io_fd[0] = *previous_fd;
	io_fd[1] = pipe_fd[1];
	*previous_fd = pipe_fd[0];

	// создаем дочку
	int pid = fork();
	if (pid == -1)
		print_error(FATAL_ERROR, NULL, true);
	if (pid == 0)
	{
		if (io_fd[0] != 0)
		{
			if (dup2(io_fd[0], 0) == -1 || close(io_fd[0]) == -1)
				print_error(FATAL_ERROR, NULL, true);
		}
		if (io_fd[1] != 1)
		{
			if (dup2(io_fd[1], 1) == -1 || close(io_fd[1]) == -1)
				print_error(FATAL_ERROR, NULL, true);
		}


		if (execve(argv[start], argv + start, env) == -1)
			print_error("error: cannot execute ", argv[start], true);
	}
	//в родительском тоже самое кроме dup2
	if (io_fd[0] != 0)
	{
		if (close(io_fd[0]) == -1)
			print_error(FATAL_ERROR, NULL, true);
	}
	if (io_fd[1] != 1)
	{
		if (close(io_fd[1]) == -1)
			print_error(FATAL_ERROR, NULL, true);
	}
	return (is_end);

}

int main(int argc, char **argv, char **env)
{
	int previous_fd = 0;
	int cmd_count = 0;

	for (int i = 1; i < argc; ++i)
	{
		if (strcmp(argv[i], ";") == 0)
			continue;
		if (strcmp(argv[i], "cd") == 0)
			my_cd(argv, &i);
		else
		{
			//если не дошли до конца команды (;), то exec == false
			t_boolean res = exec(argv, &i, env, &previous_fd);
			cmd_count++;
			// cat | cat | cat | cat
			if (res)
			{
				for (int j = 0; j < cmd_count; ++j)
				{
					//waitpid(-1, NULL, 0) - ждем любой дочерний процесс (=-1) если у нас не
					// получилось дождаться
					if (waitpid(-1, NULL, 0) == -1)
						print_error(FATAL_ERROR, NULL, true);
				}
				cmd_count = 0;
			}
		}
	}
	for (int j = 0; j < cmd_count; ++j)
	{
		//waitpid(-1, NULL, 0) - ждем любой дочерний процесс (=-1) если у нас не
		// получилось дождаться
		if (waitpid(-1, NULL, 0) == -1)
			print_error(FATAL_ERROR, NULL, true);
	}
	return (0);
}
