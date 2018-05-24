#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int startNum = 1;

	if (n <= 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - startNum; j++)
				printf(" ");

			for (int j = 0; j < startNum; j++)
				printf("%d", startNum + j);
			for (int j = 1; j < startNum; j++)
				printf("%d", startNum * 2 - j - 1);

			startNum++;
			printf("\n");
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - startNum; j++) {
				printf("  ");
			}
			if (startNum <= 5)
				for (int j = 0; j < startNum; j++)
					printf(" ");
			else if (startNum < 10)
				for (int j = 0; j < 10 - startNum; j++)
					printf(" ");
			for (int j = 0; j < startNum; j++)
				printf("%d", startNum + j);
			for (int j = 1; j < startNum; j++)
				printf("%d", startNum * 2 - j - 1);

			startNum++;
			printf("\n");
		}
	}
	return 0;
}