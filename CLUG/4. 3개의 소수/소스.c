#define CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int temp = 0;
	int j;
	double n;
	int number = 0;
	int prime[168] = { 0 };

	for (int i = 2; i <= 1000; i++)
	{
		n = sqrt(i);

		for (j = 2; j <= n; j++)
		{
			if ((i % j) != 0)
				temp += 1;
		}
		if ((n - 2) < temp)
			prime[number++] = i;
		temp = 0;
	}

	int T;
	scanf("%d", &T);
	int *testcase;
	testcase = (int *)malloc(sizeof(int) * T);
	for (int i = 0; i < T; i++)
		scanf("%d", testcase + i);
	int i, a, b, c;
	for (i = 0; i < T; i++)
	{
		for (a = 0; a <= 168; a++)
		{
			for (b = a; b <= 168; b++)
			{
				for (c = b; c <= 168; c++)
				{
					if (testcase[i] == (prime[a] + prime[b] + prime[c]))
					{
						printf("%d %d %d\n", prime[a], prime[b], prime[c]);
						break;
					}
					else if (testcase[i] < (prime[a] + prime[b] + prime[c]))
					{
						c = 169;
					}
					else if (testcase[i] < (prime[a] + prime[a] + prime[a]))
					{
						printf("0\n");
						break;
					}
				}
				if ((testcase[i] == prime[a] + prime[b] + prime[c]) || (testcase[i] < prime[a] + prime[a] + prime[a]))
					break;
			}
			if ((testcase[i] == prime[a] + prime[b] + prime[c]) || (testcase[i] < prime[a] + prime[a] + prime[a]))
				break;
		}
	}

	return 0;
}