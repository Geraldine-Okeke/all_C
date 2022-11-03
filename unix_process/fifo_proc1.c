#include "all.h"
/*
 *a program showing how fifo can be used to communicate between processes
 *two files will be created, this is the first file which will be used for
 *writing , the other will be for reading.
 *
 */
int main()
{	
	//mkfifo("sum", 0777);
	if (mkfifo("sum", 0777) == -1)
	{
		return 1;
	}
	int arr[5];
	srand(time(NULL));
	int i;
	for (i = 0; i <5; i++)
	{
		arr[i] = rand()%100;
	
	int fd = open("sum", O_WRONLY);
		if (fd == -1)
		{
			return 2;
		}
	//write(fd , arr[i], sizeof(int));
	if (write(fd, &arr[i], sizeof(int)) == -1)
	{
		return 3;
	}
	printf("wrote %d\n", arr[i]);
	close(fd);
	}
	return 0;
}
