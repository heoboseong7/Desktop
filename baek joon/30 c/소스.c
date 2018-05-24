#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return strcmp((char*)b, (char*)a);
}
int main()
{
	char number[100001];
	scanf("%s", number);
	int n = strlen(number);
	int TF = 0;
	for (int i = 0; i < n; i++)
		TF += number[i] - 48;

	qsort(number, n, sizeof(char), compare);

if (TF > 0 && (TF % 3 == 0))
	{
		if (number[n - 1] != '0')
		{
			printf("-1");
			return 0;
		}
		else
		{
			for (int i = 0; i < n; i++)
				printf("%c", number[i]);
		}
	}
	else
		printf("-1");

	return 0;
}