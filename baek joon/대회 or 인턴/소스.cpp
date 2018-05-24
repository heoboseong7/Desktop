#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m, k;
	int team = 0;
	int rest;
	scanf("%d %d %d", &n, &m, &k);

	while (n >= 2 && m >= 1)
	{
		n -= 2;
		m -= 1;
		team++;
	}

	rest = n + m;
	while (rest < k)
	{
		team--;
		rest += 3;
	}

	printf("%d", team);

	return 0;
}