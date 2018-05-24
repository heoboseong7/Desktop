#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()	{
	int n;
	int sum = 0;

	scanf("%d", &n);
	char *num;
	num = (char *)malloc(sizeof(char) * n + 1);

	scanf("%s", num);
	for (int i = 0; i < n; i++)	{
		if (num[i] > 47 && num[i] < 58)
			sum += num[i] - 48;
	}

	printf("%d", sum);

	free(num);
	return 0;
}