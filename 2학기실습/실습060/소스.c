#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// ctrl + z = Á¾·á
	char a[101];
	while (gets(a))
		puts(a);
	return 0;
}