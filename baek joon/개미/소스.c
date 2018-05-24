#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int minimum(int arr[], int n, int length)

int main()
{
	int n1, n2;
	int *p;
	int l;

	scanf("%d", &n2);
	scanf("%d %d", &l, &n2);
	p = (int *)malloc(sizeof(int) * n2);
	for (int i = 0; i < n2; i++)
		scanf("%d", &p[i]);
	printf("%d", l - p[minimum(p, n2, l)]);



}

int minimum(int arr[], int n, int length)
{
	int center = length / 2 + 1;
	int max = abs(arr[0] - center);
	int nmax = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (max > abs(arr[i + 1] - center))
		{
			max = abs(arr[i + 1] - center);
			nmax = arr[i + 1];
	}
	return nmax;
}