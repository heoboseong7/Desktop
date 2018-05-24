#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int** Matadd1(int m[][3], int n[][3])
{
	int sum[3][3] = { 0 };
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			sum[i][j] = m[i][j] + n[i][j];
	return sum;
}
int main()
{
	int a[3][3] = { 0 };
	int b[3][3] = { 0 };

	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			scanf("%d", &a[i][j]);

	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			scanf("%d", &b[i][j]);

	int **temp = Matadd1(a, b);

	printf("%d", temp[1][1]);

	return 0;
}