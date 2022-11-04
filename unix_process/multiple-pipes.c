#include "all.h"
/*
 *in this program a parent process will have two child process(child1 and child2), the parent process will generate a number x, which will be read by child1, child1 will add 5 to x and send it to child2, child2 will add another 5 to it and send it back to the parent. therefore, the code will have 3 pipes, since it has 3pipes, there will be 6 file descriptors, recall each pipe has 2 opening(read[0] and write[1])
*parent writes(fd[0][1]) to --->child1: reads(fd[0][0]) from parent, then writes(fd[1][1]) to -------->child2:child2 reads(fd[1][0]) what was sent to it from child1, then writes(fd[2][1]) to----->parent: the parent reads(fd[2][0]) sent from child2
*/
int main()
{
	int fd[3][2];
	int i;
	for(i = 0;i <3; i++)
	{
		if (pipe(fd[i]) < 0)
		{
			return 1;
		}
	}
	int pid1 = fork();
	if (pid1 < 0)
	{
		return 2;
	}
	if (pid1 == 0)
	{
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		int x;
	if (read(fd[0][0], &x, sizeof(x)) < 0)
	{
		return 3;
	}
	x+= 5;
        if (write(fd[1][1], &x, sizeof(x)) < 0)
	{
		return 4;
	}
	close(fd[0][0]);
	close(fd[1][1]);
	return 0;
	}
	int pid2 = fork();
	if (pid2 < 0)
	{
		return 5;
	}
	if (pid2 == 0)
	{
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);
		int x;
	if (read(fd[1][0], &x, sizeof(x)) < 0)
	{
		return 6;
	}
	x+= 5;
	if ( write(fd[2][1], &x, sizeof(x)) < 0)
	{
		return 7;
	}
	close(fd[1][0]);
	close(fd[2][1]);
	return 0;
	}
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[2][1]);
	int x = 0;
	if (write(fd[0][1], &x, sizeof(x)) < 0)
	{
		return 8;
	}
	if (read(fd[2][0], &x, sizeof(x)) < 0)
	{
		return 9;
	}
	printf("the result is %d\n", x);
	close(fd[0][1]);
	close(fd[2][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}

