#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
/*
 *this is a program to open a file , write into it and close
 * if fp is NULL, exit
 *return 0;
 */
int main()
{
	FILE* fp;
	char text[20];
	
	fp = fopen("my_file.txt", "w");
	if (fp == NULL)
	{
		printf("file opening unsuccesfull\n");
		exit(1);
	}
	else
	{
		printf("file opening succesfull\n");
	}
	if (strlen(text) > 0)
	{
		fputs(text, fp);
		fputs("\n", fp);
	}
	fclose(fp);
	printf("data written succesfully in my_file.txt and also close\n");
	return (0);
}
