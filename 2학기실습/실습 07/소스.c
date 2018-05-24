#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char line[101];
	char *ptrline = line;
	printf("Enter one line of string : ");
	gets(line);

	printf("Forward print            : ");
	for (int i = 0; i < strlen(line); i++) // while(*(ptrline + i) \n putchar(*(ptrline + i);
		printf("%c", *(ptrline + i));
	printf("\n");

	printf("Backward print           : ");
	for (int i = 0; i < strlen(line); i++)
		printf("%c", *(ptrline + strlen(line) - 1 - i));
	printf("\n");

	return 0;
}