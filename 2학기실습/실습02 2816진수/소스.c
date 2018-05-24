#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	do {
		printf("정수를 입력해 주세요 (0 입력시 종료) : ");

		scanf("%d", &n);
		// 0 입력시 제어문 빠져나옴
		if (n == 0)
			break;

		int size2 = 32;
		int size8 = 10;
		int size16 = 8;
		int i;

		// 2진수 변환 후 출력
		printf("2진수 : ");

		for (i = 0; i < size2; i++)
		{
			if (n >> size2 - 1 - i & 1) {
				printf("1");
			}

			else {
				printf("0");
			}
		}

		printf("\n");

		// 8진수 변환 후 출력

		int eight = 0;
		for (i = 0; i < size8; i++)
		{
			switch (n >> 3 * i & 7)
				default:
					eight += (n >> 3 * i & 7) * pow(10, i);
		}

		printf("8진수 : %32d", eight);
		printf("%8o\n", n);

		// 16진수 변환 후 출력
		printf("16진수:                         ");

		for (i = 0; i < size16; i++)
		{
			if (i == 0 && ((n >> size2 - (4 * i + 4) & 15) == 0))
				printf(" ");

			if (1 <= (n >> size2 - (4 * i + 4) & 15) && (n >> size2 - (4 * i + 4) & 15) <= 9)
				printf("%d", n >> size2 - (4 * i + 4) & 15);
			else if (10 <= (n >> size2 - (4 * i + 4) & 15) && (n >> size2 - (4 * i + 4) & 15) <= 15)
				printf("%c", (n >> size2 - (4 * i + 4) & 15) + 55);
			else if (i >= 1 && (n >> size2 - (4 * i + 4) & 15) == 0)
				if ((n >> size2 - (4 * i)) == 0)
					printf(" ");
				else
					printf("0");
		}

		printf("%8X\n", n);
	} while (n != 0); // 0 입력시 반복문 종료

	return 0;
}