#include "all.h"
/*
 *a program showing how fifo operates.
 *fifo works similarly with pipe,infact it is a named pipe.
 *in fifo, for the program to execute completely, the two ends(write and read must be opened unlike in pipe
 *
 */
int main()
{
	//mkfifo("myfifo", 0777);
	//the above will create a file named 'myfifo',with permision to all        //users. the file will be created in your working directory
	if (mkfifo ("myfifo",0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("failed to create a file");
			return 1;
		}
	}
	//time to open, write and read into the file
	printf("opening\n");
	int fd = open("myfifo", O_RDWR);
	printf("opened\n");
	if (fd == -1)
	{
		printf("failed to open the file");
		return 2;
	}
	int x = 97;
	//write(fd , &x, sizeof(x));
	if (write(fd, &x, sizeof(x))== -1)
	{
		printf("unable to write into fd");
		return 3;
	}
	printf("written\n");
	close(fd);
	printf("closed\n");
	return 0;
}
