#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c;
	int *ptra = &a;
	int *ptrb = &b;
	do
	{
		printf("enter the numbers : ");

		scanf("%d %d", &a, &b);
		printf("numbers entered : %d %d\n", a, b);

		a = a + b;
		b = a - b;
		a = a - b;

		printf("swap by direct access : %d %d\n", a, b);

		*ptra = *ptra + *ptrb;
		*ptrb = *ptra - *ptrb;
		*ptra = *ptra - *ptrb;

		printf("swap by indirect access : %d %d\n", a, b);

		printf("종료하려면 0, 계속하려면 아무 숫자나 입력해주세요. : ");

		scanf("%d", &c);
	} while (c != 0);

	return 0;
}