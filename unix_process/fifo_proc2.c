#include "all.h"
/*
 *this is the second program for reading
 *
 */
int main()
{
	int arr[5];
	int fd = open("sum", O_RDONLY);
	if (fd == -1)
	{
		return 1;
	}
	int i;
	for ( i = 0; i < 5; i++)
	{
	    if	(read(fd, &arr[i], sizeof(int)) == -1)
	    {
		    return 2;
	    }
	    printf("read %d", arr[i]);
	}
	close(fd);
	int sum = 0;
	for (i =0; i< 5; i++)
	{
		sum+= arr[i];
	}
	printf("result = %d", sum);
	return 0;
}
