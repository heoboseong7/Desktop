#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int choose;
	int a, b;
	int temp;
	do {
		printf("방법을 선택하세요.\n0. Exit\n1. Temporary variable\n2. Addition/subtraction\n3. Multiply/division\n4. Exclusive OR\n\n");

		scanf("%d", &choose);

		switch (choose) {
		case 0:
			break;
		// Temporary variable
		case 1:
			printf("두 정수를 입력하세요\n");
			scanf("%d %d", &a, &b);
			temp = a;
			a = b;
			b = temp;
			printf("결과 : %d %d\n", a, b);
			break;
		// Addition/subtraction
		case 2:
			printf("두 정수를 입력하세요\n");
			scanf("%d %d", &a, &b);
			a = a + b;
			b = a - b;
			a = a - b;
			printf("%결과 : d %d\n", a, b);
			break;
		// Multiply/division
		case 3:
			printf("두 정수를 입력하세요\n");
			scanf("%d %d", &a, &b);
			a = a * b;
			b = a / b;
			a = a / b;
			printf("결과 : %d %d\n", a, b);
			break;
		// Exclusive OR
		case 4:
			printf("두 정수를 입력하세요\n");
			scanf("%d %d", &a, &b);
			a = a ^ b;
			b = a ^ b;
			a = a ^ b;
			printf("결과 : %d %d\n", a, b);
		//1 ~ 4 이외의 값 입력시 제어문을 빠져나옴
		default:
			break;
		}
	} while (1 <= choose && choose <= 4);
	
	return 0;
}