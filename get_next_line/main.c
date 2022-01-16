#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include "get_next_line.h"

int main()
{
	int fd = open("../test.txt", O_RDONLY);
	char *s;
	int status;
	printf("==================================\n");
	status = get_next_line(fd, &s);
	while(status == 1)
	{
		printf("%s|\n", s);
		free(s);
		status = get_next_line(fd, &s);
	}
	if (status == 0)
	{
		printf("%s&\n", s);
		free(s);
		status = get_next_line(fd, &s);
	}
	printf("==================================\n");
	close(fd);
	return 0;
}
