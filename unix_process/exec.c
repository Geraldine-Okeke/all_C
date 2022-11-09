#include "all.h"

int main()
{
	char cmd[] = "/usr/bin/ls";
	char *argvev[] = {"ls","-l", NULL};
	char *envvec[] = {NULL};
	
	printf("start of execv call %s \n", cmd);
	if (execve(cmd, argvev, envvec) == -1)
	{
		printf("failed to execute");
	}
	printf("oops , something went wrong");
	return 0;
}
