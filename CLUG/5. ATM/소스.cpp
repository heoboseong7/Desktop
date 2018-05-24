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
	int n;
	int i = 0;
	int time = 0;
	scanf("%d", &n);
	int a[1001] = { 0 };
	while (i < n)
		scanf("%d", a + i++);
	qsort(a, i, sizeof(int), compare);
	
	i = 0;
	while (a[i])
		time += (i + 1) * a[n - 1 - i++];

	printf("%d", time);
	return 0;
}