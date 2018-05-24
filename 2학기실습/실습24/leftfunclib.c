#include "header.h"

void ltrivial(int arr[], int d, int n)
{
	int *temp;
	temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = 0; i < n - d; i++)
	{
		arr[i] = temp[d + i];
	}
	for (int i = 0; i < d; i++)
		arr[n - d + i] = temp[i];

	free(temp);
}

void ljuggling(int arr[], int d, int n)
{
	int k;
	for (int i = 0; i < gcd(n, d); i++)
	{
		int j = i;
		int temp = arr[i];
		while (1)
		{
			k = (j + d) % n;

			if (k == i)
				break;

			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}

void lblock_swap(int arr[], int d, int n)
{
	if (d == n || d == 0)
		return;

	if (n - d == d)
	{
		swap(arr, 0, n - d, d);
		return;
	}
	else if (n - d > d)
	{
		swap(arr, 0, n - d, d);
		lblock_swap(arr, d, n - d);
	}
	else
	{
		swap(arr, 0, d, n - d);
		lblock_swap(arr + n - d, 2 * d - n, d);
	}
}

