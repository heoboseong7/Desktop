#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char fname[] = "test.txt";
	char line[101];
	FILE *f;

	if (fopen_s(&f, fname, "w") != 0)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	};

	fgets(line, 80, stdin);
	fputs(line, f);
	fclose(f);

	if (fopen_s(&f, fname, "r") != 0)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	};
	fgets(line, 80, f);
	printf("%s\n", line);
	fclose(f);

	return 0;
}