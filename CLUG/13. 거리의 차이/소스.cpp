#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	long long int a[10020] = { 0 };
	long long int sum = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
		{
			if (a[i] - a[j] > 0)
				sum += a[i] - a[j];
			else if (a[i] - a[j] < 0)
				sum -= a[i] - a[j];
		}
	
	printf("%lld", sum * 2);

	return 0;
}