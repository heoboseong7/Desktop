#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char * reverse(char *str1)
{
	int i = 0;
	char temp[101];
	while (str1[i])
		temp[i] = *(str1 + i++);
	int length = i;
	for (int j = 0; j < length; j++)
		*(str1 + j) = temp[length - 1 - j];
	return str1;
}
char * encrypt3(char * str1)
{// 65 ~ 90, 97 ~ 122
	int i = 0;
	while (*(str1 + i))
	{
		if (*(str1 + i) <= 87)
			*(str1 + i) += 3;
		else if (*(str1 + i) <= 90)
			*(str1 + i) -= 23;
		else if (*(str1 + i) <= 119)
			*(str1 + i) += 3;
		else if (*(str1 + i) <= 122)
			*(str1 + i) -= 23;
		i++;
	}
	return str1;
}
char * rotate5(char * str1)
{
	int temp[101];
	int length = 0;
	while (*(str1 + length))
		temp[length] = *(str1 + length++);

	for (int i = 0; i < length; i++)
	{
		if ((i + 4) < length)
			*(str1 + i + 4) = temp[i];
		else
			*(str1 + i + 4 - length) = temp[i];
	}	
	return str1;
}
int main()
{
	char line[101];
	char function1[101] = { NULL };
	char function2[101] = { NULL };
	char function3[101] = { NULL };

	printf("Enter one line of string : ");
	gets(line);
	int i = 0;
	while (line[i])
		i++;

	for (int j = 0; j < i; j++)
	{
		function1[j] = *(line + j);
		function2[j] = *(line + j);
		function3[j] = *(line + j);
	}

	reverse (function1);
	encrypt3 (function2);
	rotate5 (function3);

	printf("\nString Entered : ");
	puts(line);
	printf("\n");
	printf("Reversed :  ");
	puts(function1);
	printf("\n");
	printf("Encrypted : ");
	puts(function2);
	printf("\n");
	printf("Rotated :   ");
	puts(function3);
	printf("\n");

	return 0;
}