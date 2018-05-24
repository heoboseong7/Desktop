#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MatAdd1(int *m, int *n)
{
	for (int i = 0; i <= 8; i++)
			*(m + i) = *(m + i) + *(n + i);
}
void MatAdd2(int *m[][3], int *n[][3])
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			*m[i][j] = *m[i][j] + *n[i][j];
}
void Matprod1(int *m, int *n, int *save)
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			for (int k = 0; k <= 2; k++)
				*(save + 3 * i + j) += *(m + 3 * i + k) * *(n + j + 3 * k);
}
void Matprod2(int *m[][3], int *n[][3], int *save[][3])
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			for (int k = 0; k <= 2; k++)
				*save[i][j] += *m[i][k] * *n[k][j];
}
int main()
{
	int a[3][3] = { 0 };
	int b[3][3] = { 0 };
	int save[3][3] = { 0 };
	int *ptra[3][3];
	int *ptrb[3][3];
	int *ptrsave[3][3];

	printf("1개씩 3 * 3 배열 입력 : ");
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			scanf("%d", &a[i][j]);
			ptra[i][j] = &a[i][j];
		}
	printf("1개씩 3 * 3 배열 입력 : ");
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			scanf("%d", &b[i][j]);
			ptrb[i][j] = &b[i][j];
		}

	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			ptrsave[i][j] = &save[i][j];

	int method;
	printf("방법을 선택하세요\n");
	printf("1. Matadd - arrayindex\n");
	printf("2. Matadd - pointer\n");
	printf("3. Matprod - array index\n");
	printf("4. Matprod - pointer\n");
	scanf("%d", &method);

	int *temp;

	switch (method)
	{
	case 1:
		MatAdd1(a, b);
	case 2:
		MatAdd2(ptra, ptrb);
	case 3:
		Matprod1(a, b, save);
	case 4:
		Matprod2(ptra, ptrb, ptrsave);
	}

	if (method == 1 || method == 2)
	{
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
				printf("%3d", a[i][j]);
			printf("\n");
		}
	}
	else if (method == 3 || method == 4)
	{
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
				printf("%5d", save[i][j]);
			printf("\n");
		}
	}
	return 0;
}