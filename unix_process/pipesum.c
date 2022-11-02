#include "all.h"
/* this program wil have an array of numbers, half of the numbers will be s/*umed and assigned the child process , while the other half will be sumed
* and assigned to th main process, piping will be used to get the total sum*
*/
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int arrsize = sizeof(arr) / sizeof(int);
	int start , end;
	int fd[2];
	pipe(fd);
	
	if (pipe(fd) == -1)
	{
		printf("piping failed");
		return 1;
	}
	int id = fork();
	if (id == -1)
	{
		printf("failed to fork");
		return 2;
	}
	if (id == 0)
	{
		start = 0;
		end = arrsize/2;
	}
	else
	{
		start = arrsize/2;
		end = arrsize;
	}
	int sum, i;
	for (i = start; i < end; i++)
	{
		sum += arr[i];
	}
	printf("the partial sum is %d\n", sum);
	if (id == 0)
	{
		//fd[0]= read,fd[1] = write
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		int sumX;
		close(fd[1]);
		read(fd[0], &sumX, sizeof(sumX));
		close(fd[0]);
	
	        int totalsum = sum + sumX;
	        printf("the total sum is %d ", totalsum);
	}
	return 0;
}
