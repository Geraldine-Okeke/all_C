#include "all.h"
/*
 * a program showing showing the id of the two process
 *the child process is the one with 0 id
 *return 0;
 */

int main()
{
	int id = fork();
		
	printf("helloworld from id : %d\n ", id);
	return 0;
}
