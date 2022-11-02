#include "all.h"
/*
 *main: entry point
 *fork(): a function that creates two process , child and parent process
 *
 *return 0;
 */
int main()
{
	fork();
		printf("hello world\n");
	return 0;
}

/* calling the fork() twice will print the above four times.
 * the arithmetics of this is 2^n , where any is the number of times fork()is called
 * from the above, calling fork() 3 times, will print the input 8times , i.e 2^3.
 */

