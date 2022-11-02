#include "all.h"
/*
 *this code will print numbers 1 -5 in the child process and 6-10 in the main process
 *the code will also show how wait() worksi
 *return 0
 */
int main()
{
	pid_t cpid;
	//pid_t is a process identification data type in c;
	int id = fork();
	int n , i;
	
	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if(id != 0)
	{
		cpid = wait(NULL);
	}
	for (i = n ; i < n+ 5; i++)
	{
		printf("%d", i);
		fflush(stdout);
	}
	printf("\n");
	return 0;
}

