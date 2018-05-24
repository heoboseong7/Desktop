#include "header.h"

void rtrivial(int arr[], int d, int n)
{
	int *temp;
	temp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = 0; i < n - d; i++)
	{
		arr[d + i] = temp[i];
	}
	for (int i = 0; i < d; i++)
		arr[i] = temp[n - d + i];

	free(temp);
}

void rjuggling(int arr[], int d, int n)
{
	reverse(arr, 0, n - 1);
	ljuggling(arr, d, n);
	reverse(arr, 0, n - 1);
}

void rblock_swap(int arr[], int d, int n)
{
	reverse(arr, 0, n - 1);
	lblock_swap(arr, d, n);
	reverse(arr, 0, n - 1);
}

