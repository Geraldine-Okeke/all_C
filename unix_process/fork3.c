#include "all.h"
/*
 * this code wil print the result 3 times
 * return 0
 */
int main()
{
	int id = fork();
		if (id != 0)
		{
		fork();
		}
		printf("hello world\n");
		return 0;
}
