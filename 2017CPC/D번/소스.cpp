#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if ((*(double*)a) > (*(double*)b))
		return 1;
	else if ((*(double*)a) == (*(double*)b))
		return 0;
	else
		return -1;

}

int findmax(double *a)
{
	int max = 0;
	for (int i = 1; i < 7; i++)
		if (a[max] < a[i])
			max = i;

	return max;
}
int main()
{
	int n;
	int i;
	scanf("%d", &n);

	double theseven[7];
	double score;
	for (i = 0; i < 7; i++)
		scanf("%lf", theseven + i);

	for (i = 7; i < n; i++)
	{
		scanf("%lf", &score);
		if (theseven[findmax(theseven)] > score)
			theseven[findmax(theseven)] = score;
	}

	qsort(theseven, 7, sizeof(double), compare);

	for (i = 0; i < 7; i++)
		printf("%.3lf\n", theseven[i]);

	return 0;
}