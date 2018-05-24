#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *f;
	if (fopen_s(&f, argv[1], "r") != 0)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	int linecnt = 1, wordcnt = 1, charcnt = 0;
	char line2[80];
	fgets(line2, 80, f);
	char line;
	while ((line = fgetc(f)) != EOF)
	{
		if (line == '\n')
			linecnt++;
		else if (line == ' ')
			wordcnt++;
		else
			charcnt++;
	}
	printf("<COUNT RESULT>\n");
	printf("%d\n", linecnt);
	printf("%d\n", wordcnt);
	printf("%d\n", charcnt);

	fclose(f);

	char filename[100] = { NULL };
	int i = 0;
	while (argv[1][i] != '.')
	{
		filename[i] = argv[1][i++];
	}
	strcat(filename, ".rev");
	FILE *revf;
	fopen_s(&revf, filename, "w");
	fopen_s(&f, argv[1], "r");

	while ((line = getc(f)) != EOF)
	{
		if (line >= 97 && line <= 122)
			fputc(line - 32, revf);
		else if (line >= 65 && line <= 90)
			fputc(line + 32, revf);
		else
			fputc(line, revf);
	}
	printf("File saved in %s\n", filename);

	fclose(f);
	fclose(revf);
	return 0;
}