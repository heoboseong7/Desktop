#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);

	printf("%.10lf", a / b);

	return 0;
}