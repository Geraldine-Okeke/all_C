#include "all.h"
/*
 *a program showing how to break strings using strtok
 *return 0
 */
int main()
{
	char str[] = "this is a string to break";
	char *piece = strtok(str, " ");
	while (piece != NULL)
	{
		printf("%s\n", piece);
		piece = strtok(NULL, " ");
	}
	return 0;
}
