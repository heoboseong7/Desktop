#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char fname[] = "grate.txt";
	FILE *f;
	char name[80];
	int cnt = 0;

	if (fopen_s(&f, fname, "w") != 0)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	};
	fgets(name, 80, stdin);

	while (!feof(stdin))
	{
		fprintf(f, "%d", ++cnt);
		fputs(name, f);
		fgets(name, 80, stdin);
	}
	fclose(f);

	return 0;
}