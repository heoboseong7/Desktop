#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int arr[50];
	char fname[] = "save.bin";

	FILE *f;

	fopen_s(&f, fname, "wb+");

	for (int i = 0; i < 50; i++)
	{
		arr[i] = 3 * i;
		putw(arr[i], f);
	}
	
	rewind(f);

	for (int i = 0; i < 25; i++)
	{
		printf("%d\n", getw(f));
		fseek(f, 4L, SEEK_CUR);
	}

	fclose(f);

	return 0;
}