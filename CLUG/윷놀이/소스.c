#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()

{
	int temp[3] = { 0 };
	int a[12] = { 0 };
	for (int j = 0; j <= 2; j++)
	{
		for (int i = 0; i <= 3; i++)
		{
			scanf("%d", a + i + 4 * j);
			if ((*(a + i + 4 * j) & 1) == 0)
				temp[j] += 1;
		}
	}


	for (int i = 0; i <= 2; i++)
	{
		if (temp[i] == 0)
			printf("E\n");
		else
			printf("%c\n", temp[i] + 64);
	}

	return 0;
}