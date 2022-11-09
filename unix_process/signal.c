#include "all.h"
/*
 *a program that shows how signals work in C
 *
 */
int main()
{
	int pid = fork();
	
	if (pid == -1)
	{
		printf("fork failed");
		return 1;
	}
	if (pid == 0)
	{
		while(1)
		{
			printf("this is how i operate\n");
			usleep(50000);
		
		}
	}
	else
	{
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return 0;
}

