#include "header.h"

int* gendata(char *arr, int *n, int *d)
{
	srand((unsigned)time(NULL));
	*n = rand() % 1 + 500000;
	*d = rand() % (*n);
	if (rand() % 2)
		*d *= -1;
	
	arr = (char *)malloc(sizeof(int) * (*n));
	for (int i = 0; i < (*n); i++)
		arr[i] = (rand() % 26) + 65;

	return arr;
}

void printarr(char arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%c ", arr[i]);
	printf("\n");
}