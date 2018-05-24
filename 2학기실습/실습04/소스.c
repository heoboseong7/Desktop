#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void TempSwap(int *m, int *n)
{
	int temp;
	temp = n;
	n = m;
	m = temp;
}
void Add_Swap(int *m, int *n)
{
	*m = *m + *n;
	*n = *m - *n;
	*m = *m - *n;
}
void MultSwap(int *m, int *n)
{
	*m = *m * *n;
	*n = *m / *n;
	*m = *m / *n;
}
void ExclSwap(int *m, int *n)
{
	*m = *m ^ *n;
	*n = *m ^ *n;
	*m = *m ^ *n;
}

int main()
{
	int a, b, c;

	do
	{
	printf("두 정수를 입력해 주세요 : ");
	scanf("%d %d", &a, &b);

	printf("방법을 선택해 주세요\n");
	printf("1. TempSwap\n");
	printf("2. Add Swap\n");
	printf("3. MultSwap\n");
	printf("4. ExclSwap\n");

	scanf("%d", &c);

	switch (c)
	{
	case 1:
		TempSwap(&a, &b);
	case 2:
		Add_Swap(&a, &b);
	case 3:
		MultSwap(&a, &b);
	case 4:
		ExclSwap(&a, &b);
	}
	printf("%d %d", a, b);

	printf("종료하려면 0 다시 하려면 아무 숫자나 입력해 주세요 : ");
	scanf("%d", &a);
} while (a != 0);
	return 0;
}