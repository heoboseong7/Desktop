#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct inf
{
	int a;
	int b;
};
int main()
{
	int n;
	int sum = 0;
	inf x[101];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i].a, &x[i].b);

	for (int i = 0; i < n; i++)
		sum += x[i].a * x[i].b;

	printf("%d", sum);

	return 0;
}