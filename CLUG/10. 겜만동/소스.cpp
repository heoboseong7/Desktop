#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int a[101] = { 0 };
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	int cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[n - i] <= a[n - i - 1])
		{
			cnt += a[n - i - 1] - a[n - i] + 1;
			a[n - i - 1] -= a[n - i - 1] - a[n - i] + 1;
		}
	}
	printf("%d", cnt);
	return 0;
}