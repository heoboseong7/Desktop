#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>

int main()
{
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);

	int c;

	c = a / (10 ^ b);

	printf("%d", c);


	return 0;
}