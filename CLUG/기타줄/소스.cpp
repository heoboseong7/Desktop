#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n, m; //n <= 100, m <= 50
	int set[51];
	int one[51];
	int nset;
	int none;
	int price[3];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d", set + i, one + i);

	qsort(set, m, sizeof(int), compare);
	qsort(one, m, sizeof(int), compare);

	nset = (n - (n % 6)) / 6;
	none = n % 6;

	price[0] = n * one[0];

	if (n % 6 != 0)
		price[1] = (nset + 1) * set[0];
	else
		price[1] = nset * set[0];
	
	price[2] = nset * set[0] + none * one[0];

	qsort(price, 3, sizeof(int), compare);

	printf("%d", price[0]);

	return 0;
}