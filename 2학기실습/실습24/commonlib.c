#include "header.h"

void gendata(int arr[], int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100 + 1;
}

void printarr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

void swap(int arr[], int s, int t, int d)
{
	for (int i = 0; i < d; i++)
	{
		int temp = arr[s + i];
		arr[s + i] = arr[t + i];
		arr[t + i] = temp;
	}
}

void reverse(int arr[], int start, int end)
{
	for (int i = 0; i < ((end - start + 1) / 2); i++)
	{
		int temp = arr[start + i];
		arr[start + i] = arr[end - i];
		arr[end - i] = temp;
	}
}

void _reverse(int arr[], int d, int n)
{
	if (d > 0)
	{
		reverse(arr, n - d, n - 1);
		reverse(arr, 0, n - 1 - d);
		reverse(arr, 0, n - 1);
	}
	else if (d < 0)
	{
		d = -d;
		reverse(arr, 0, d - 1);
		reverse(arr, d, n - 1);
		reverse(arr, 0, n - 1);
	}
}