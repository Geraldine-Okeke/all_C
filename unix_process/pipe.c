#include "all.h"
/*
 *:a program showing how pipe() can be used with fork()
 *: literally, a pipe has 2 openings, so the pipe() takes two integers
 *: return 1 if fork fails
 *: return 2 if pipe fails
 *
 */
int main()
{
	int fd[2]; //fd means file descriptor, which is an array of 2 inte
	//gers, fd[0] = read, fd[1] = write
	pipe(fd);
	if (pipe(fd) == -1)
	{
		printf("piping failed");
		return 1;
	}
	int id = fork();
	if(id == -1)
	{
		printf("failed to fork");
		return 2;
	}
	if (id == 0)
	{
		//to write ,you have to close the other end of the pipe
		//which is read
		close(fd[0]);
		int x;
		printf("enter a value: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int))== -1)
		{
			printf("failed to write into fd[1]");
			return 3;
		}
		close(fd[1]);
		return 0;
	}
	else
	{
		//to read,you have to close the other end of the pipe whic
		//h is write
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int))== -1)
		{
			printf("failed to read from fd[0]");
			return 4;
		}
		close(fd[0]);
		printf("read %d from child process\n", y);
	}
	return 0;
}
		
