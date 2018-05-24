#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[1000001];
	gets(str);
	int nspace = 1;
	int i = 1;
	
	if ((((str[0] >= 65) && (str[0] <= 90)) || ((str[0] >= 97) && (str[0] <= 122))) == 0)
		nspace--;

	while (str[i])
	{
		if ((32 == str[i]) && ((str[i + 1] != 32) && (str[i + 1] != 0)))
			nspace++;
		i++;
	}

	printf("%d\n", nspace);

	return 0;
}