#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct num
{
	char cnum[17];
};

int main()
{
	int n;
	scanf("%d", &n);

	num a[1001];
	int result[1001] = { 0 };
	int sum[1001] = { 0 };
	for (int i = 0; i < n; i++)
		scanf("%s", a[i].cnum);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 16; j++)
		{
			a[i].cnum[j] -= 48;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 16; j += 2)
		{
			if (a[i].cnum[j] * 2 >= 10)
				a[i].cnum[j] = a[i].cnum[j] * 2 - 9;
			else
				a[i].cnum[j] *= 2;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 16; j++)
			sum[i] += a[i].cnum[j];

	for (int i = 0; i < n; i++)
		if (sum[i] % 10 != 0)
			printf("F\n");
		else
			printf("T\n");

	return 0;
}