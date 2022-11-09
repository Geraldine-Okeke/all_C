#include "all.h"
/*
 *how to use a user-defined signal in C
 */
int x = 0;
void handle_sigusr1(int sig)
{
	if (x == 0)
	{
		printf("\nHint: multiplication is a repetitive addition\n");
	}
}

int main()
{
	int pid = fork();
	if (pid == -1)
	{
		return 1;
	}
	if (pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		printf("what is the result of multiplication of 4 and 3 ? ");
		scanf("%d", &x);
		if (x == 12)
		{
			printf("Right!");
		}
		else
		{
			printf("Wrong!");
		}
		wait(NULL);
	}
	return 0;
}

