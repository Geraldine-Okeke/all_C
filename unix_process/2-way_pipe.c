#include "all.h"
/*
 *this code shows two way communication between proccesses(child and parentusing pipes.
 *the child process will read a random number generated in the parent process, multiply it by 4 and send the result back to the parent process
 */
int main()
{
	int p1[2];//child(write[1])->parent(read[0])
	int p2[2];//parent(write[1])->child(read[0])
	if (pipe(p1) == -1)
	{
		return 1;
	}
	if (pipe(p2)== -1)
	{
		return 1;
	}
	int pid = fork();
	if (pid == -1)
	{
		return 2;
	}
	if (pid == 0)
	{
		close(p1[0]);
		close(p2[1]);
		int x; //generated in the parent process
		//we are in the child process
		if (read(p2[0], &x, sizeof(x)) == -1)
		{
			return 3;
		}
		printf("read %d\n", x);
		x*= 4;
		if (write(p1[1], &x , sizeof(x)) == -1)
		{
			return 4;
		}
		printf("multiplied and wrote the result :%d\n", x);
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		int y = rand()%10;//this will generate a random number betw				     //een 0-9
		if (write(p2[1], &y, sizeof(y)) == -1)
		{
			return 5;
		}
		if (read(p1[0], &y, sizeof(y)) == -1)
		{
			return 6;
		}
		printf("read the result:%d\n ", y);
		wait(NULL);
		close(p1[0]);
		close(p2[1]);
	}
	return 0;
}
