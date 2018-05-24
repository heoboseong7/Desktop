#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char a[4];
	char b[4];
	
	gets(a);
	gets(b);

	//compare
	int i = 2;
	int j = 2;
	do
	{
		if (a[i] > b[i])
			while (a[j])
				printf("%d", a[j--]);
		else if (a[i] < b[i])
			while (b[j])
				printf("%d", b[i--]);
		i--;
	} while (a[i] == b[i]);

		return 0;

}