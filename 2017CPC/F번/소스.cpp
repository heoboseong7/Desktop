#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct inf
{
	long long int c;
	long long int k;
};
int main()
{
	int n;
	long long int sum = 0;
	long long int x = pow(10, 9) + 7;
	scanf("%d", &n);

	inf a[100001];

	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &a[i].c, &a[i].k);

	for (int i = 0; i < n; i++)
		sum += a[i].c * a[i].k * pow(2, a[i].k - 1);

	if (sum >= x)
		printf("%lld", sum % x);
	else
		printf("%lld", sum);

	return 0;
}