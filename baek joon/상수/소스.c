#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char num[16];
	int time = 0;
	int i = 0;

	gets(num);

	while (num[i])
	{
		if (num[i] <= 67)
			time += 3;
		else if (num[i] <= 70)
			time += 4;
		else if (num[i] <= 73)
			time += 5;
		else if (num[i] <= 76)
			time += 6;
		else if (num[i] <= 79)
			time += 7;
		else if (num[i] <= 83)
			time += 8;
		else if (num[i] <= 86)
			time += 9;
		else if (num[i] <= 90)
			time += 10;
		i++;
	}

	printf("%d\n", time);

	return 0;
}