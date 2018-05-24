#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
	char name1[10];
	char name2[20];
} Person;

char *return_string(char *paramString);

int main()
{
	/* Test Print Method */
	printf("Hi");
	puts("Hi");

	/* Test Memory Corruption */
	Person anydog;
	scanf("%s", anydog.name1);
	puts("[anydog.name1]");
	puts(anydog.name1);
	puts("\n");
	
	*anydog.name2 = NULL;
	strcat(anydog.name2, "ABCDEFGHIJKLMN");
	puts("[anydog.name2]");
	puts(anydog.name2);
	puts("\n");

	/* Test Function */
	puts(return_string("test"));

	system("PAUSE");
	return 0;
}

char *return_string(char *paramString) {
	static char temp[100];
	strcpy(temp, paramString);
	puts("[In return_string function]");
	puts(temp);
	puts("\n");
	puts("[Out of return_string function]");
	return temp;
}