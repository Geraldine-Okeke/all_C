#include "all.h"
/*
 *a progran showing how SIGCONT and SIGSTOP operates in c
 *
 */
int main()
{
	int pid = fork();
	if (pid == -1)
	{
		return 1;
	}
	if (pid == 0)
	{
		while(1)
		{
			printf("the child process is executing\n" );
			usleep(5000);//each line prints after 15miliseconds
		}
	}
	else
	{
		kill(pid, SIGSTOP);//this stops the child process from executing
		int t;
		do
		{
			printf("how many seconds do you want the execution to last: ");
			scanf("%d", &t);
			if (t > 0)
			{
				kill(pid, SIGCONT);//this signals the child process to start executing
				sleep(t);//child process will execute for t seconds
				kill(pid, SIGSTOP);//this signals the child processs to stop executing
			}
		}
		while (t < 0);
		
			kill(pid, SIGKILL);
			wait(NULL);
	}
	return 0;
}
