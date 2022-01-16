#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include "get_next_line.h"
#include "stdlib.h"

 int main()
 {
 	int fd = open("../text.txt", O_RDONLY);
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
	//while (1);
 	return 0;
 }
//int	main(int argc, char *argv[])
//{
//	int *m = (int *) malloc(10 * sizeof (int));
//	for (int i = 0; i < 10; i++)
//	{
//		m[i] = i;
//	}
//	return 0;
//}
