#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	int n;
	int s;
	int cnt = 0;

	scanf("%d %d", &n, &s);

	int a[21] = { 0 };
	int sum[1100000] = { NULL };

	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	for (int i = 1; i < pow(2, n); i++)
		for (int j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
				sum[i - 1] += a[j];
		}

	for (int i = 0; i < pow(2, n) - 1; i++)
		if (sum[i] == s)
			cnt++;

	printf("%d", cnt);

	return 0;
}