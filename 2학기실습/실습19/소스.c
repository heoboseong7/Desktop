#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	char email[100];
	char address[1000];
}information;

int main()
{
	information inf;
	information test;
	printf("email을 입력해 주세요 :");
	fgets(inf.email, 100, stdin);
	printf("주소를 입력해 주세요 : ");
	fgets(inf.address, 1000, stdin);

	FILE *f;
	fopen_s(&f, "myinfo.txt", "w");

	fputs(inf.email, f);
	fputs(inf.address, f);

	fclose(f);

	fopen_s(&f, "myinfo.txt", "r");

	fgets(test.email, 100, f);
	fgets(test.address, 1000, f);

	printf("rev email");
	for (int i = strlen(inf.email) - 1; i >= 0; i--)
		putchar(test.email[i]);
	printf("\n\n");
	printf("rev address :");
	for (int i = strlen(inf.address) - 1; i >= 0; i--)
		putchar(test.address[i]);
	printf("\n\n");

	fclose(f);

	return 0;
}
