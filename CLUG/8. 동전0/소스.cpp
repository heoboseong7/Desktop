#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int a[11];
	int b[10] = { 0 };
	int ncoin = 0;

	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	while (k != 0)
	{
		if (a[n - 1] <= k)
		{
			k -= a[n - 1];
			ncoin++;
		}
		else if (a[n - 1] > k)
			n--;
	}
	printf("%d", ncoin);

	return 0;
}