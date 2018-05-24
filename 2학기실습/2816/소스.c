#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() 
{

	printf("정수를 입력해 주세요 : ");

	int n;
	scanf("%d", &n);

	int size2 = 32;
	int size8 = 10;
	int size16 = 8;
	int binary[32] = { 0 };
	int i;

	// 2진수 변환 후 출력
	printf("2진수 : ");

	for (i = 0; i < size2; i++)
	{
		if (n >> size2 - 1 - i & 1) {
			printf("1");
			binary[31-i] = 1;
		}

		else {
			printf("0");
			binary[31-i] = 0;
		}
	}

	printf("\n");

	// 8진수 변환 후 출력
	printf("8진수 : ");

	int eight = 0;
	for (i = 0; i < size8; i++)
	{
		if (binary[3 * i] == 1)
			eight += pow(10, i);

		if (binary[3 * i + 1] == 1)
			eight += 2 * pow(10, i);

		if (binary[3 * i + 2] == 1)
			eight += 4 * pow(10, i);
	}



	printf("%32d", eight);
	printf("%8o\n", n);
	// 16

	printf("16진수 : ");
	int temp = 0;

	for (i = size16 - 1; i >= 0; i--)
	{
		if (binary[4 * i] == 1)
			temp += 1;

		if (binary[4 * i + 1] == 1)
			temp += 2;

		if (binary[4 * i + 2] == 1)
			temp += 4;

		if (binary[4 * i + 3] == 1)
			temp += 8;

		switch (temp)
		{
		case 0:
			printf(" ");
			break;
		case 10:
			printf("A");
			break;
		case 11:
			printf("B");
			break;
		case 12:
			printf("C");
			break;
		case 13:
			printf("D");
			break;
		case 14:
			printf("E");
			break;
		case 15:
			printf("F");
			break;
		default :
			printf("%d", temp);
		}

		temp = 0;
	}

	printf("%8x\n", n);

	return 0;
}