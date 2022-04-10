extern "C"
{
#define new tripouille
#include "get_next_line.h"
#undef new
}

#include "gnl.hpp"
#include "color.hpp"
#include "check.hpp"

#include <string.h>

extern int iTest;

using namespace std;

void gnl(int fd, int r, char const * s)
{
	char * line = NULL;
	int gnlReturn = get_next_line(fd, &line);
	check(r == gnlReturn && (s == NULL ? line == NULL : !strcmp(line, s)));
	cout << endl << "tester's output: ==>|"
		<< s << "|<==" << endl << "my output:\t ==>|" << line << "|<==" << endl
		<< "tester's return: " << r << endl << "my return: " << gnlReturn << endl;
	if (s != NULL)
		mcheck(line, strlen(s) + 1);
	free(line);
	iTest++;
}
