#include <stdio.h>
int findmax(int ary[])
{
	int i = 1;
	int max = ary[0];

	while (ary[i])
	{
		if (ary[i] > max)
			max = ary[i];
		i++;
	}

	return max;
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[1001] = { NULL };
	int height[1001] = { NULL };
	int k = 0;
	int ans;

	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	for (int i = 1; i < n; i++)
	{
		if (a[i] > a[i - 1])
			height[k] += a[i] - a[i - 1];
		else
			if (height[k] != 0)
				k++;
	}

	ans = findmax(height);

	printf("%d", ans);

	return 0;
}