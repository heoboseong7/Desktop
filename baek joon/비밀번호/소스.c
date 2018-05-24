#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *str)
{
	char temp[16] = { 0 };
	int i = 0;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	int n = i;
	while (i + 1)
	{
		str[i] = temp[n - i];
		i--;
	}
}
int main()
{
	int linen;
	scanf("%d", &linen);

	char *ptrline[100] = { NULL };
	int i = 0;
	while (i < linen)
	{
		ptrline[i] = (char *)malloc(sizeof(char) * 16);
		i++;
	}

	for (i = 0; i < linen; i++)
	{
		scanf("%s", ptrline[i]);
		/*
		printf("%s\n", ptrline[i]);
		printf("%d\n", strlen(ptrline[i]));
		*/
	}

	for (i = 0; i < linen; i++)
	{
		for (int j = i; j < (linen - 1); j++)
		{
			reverse(ptrline[j + 1]);
			if (strcmp(ptrline[i], ptrline[j + 1]) == 0)
			{
				printf("%d %c", strlen(ptrline[i]), ptrline[i] + (strlen(ptrline[i]) - 1) / 2);
				return 0;
			}
			reverse(ptrline[j + 1]);
		}
	}

	return 0;
}

