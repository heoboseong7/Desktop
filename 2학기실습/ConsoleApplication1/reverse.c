#include "header.h"

// arr[start] 부터 arr[end]까지 reverse하는 함수
void reverse(char arr[], int start, int end)
{
	for (int i = 0; i < ((end - start + 1) / 2); i++)
	{
		char temp = arr[start + i];
		arr[start + i] = arr[end - i];
		arr[end - i] = temp;
	}
}

void _reverse(char arr[], int d, int n)
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