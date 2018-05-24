#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inf
{
	int age;
	int n;
	char name[101];
};

int compare(const void *a, const void *b)
{
	if (((struct inf *)a)->age > ((struct inf*)b)->age)
		return 1;
	else if (((struct inf *)a)->age < ((struct inf*)b)->age)
		return -1;
	else if (((struct inf *)a)->age == ((struct inf*)b)->age && ((struct inf *)a)->n > ((struct inf*)b)->n)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	inf *pinf = (inf*)malloc(sizeof(inf) * n);
	

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pinf[i].age);
		scanf("%s", pinf[i].name);
		pinf[i].n = i;
	}

	qsort(pinf, n, sizeof(inf), compare);

	for (int i = 0; i < n; i++)
		printf("%d %s\n", pinf[i].age, pinf[i].name);

	return 0;
}