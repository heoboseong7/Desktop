#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(int *)b - *(int *)a);
}
int main()
{
	int n;
	int weight[100001] = { 0 };
	int max;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);

	if (n == 1)
	{
		printf("%d", *weight);
		return 0;
	}

	qsort(weight, n, sizeof(int), compare);
	max = weight[0];
	for(int k = 0; k < n - 1; k++)
	{

		if (max < weight[k + 1] * (k + 2))
		{
			max = weight[k + 1] * (k + 2);
		}
	}
	printf("%d", max);
	return 0;
}