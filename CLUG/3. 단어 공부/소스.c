#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char a[1000000] = { 0 };
	int b[26] = { 0 };
	int n = 0;
	// 입력받기
		scanf("%s", a);

		for (int i = 0; i <= 999999; i++)
		{
			if (i > 0 && *(a + i - 1) == 0)
				break;
			else
				n++;
		}

	//갯수 세기
	for (int i = 0; i <= n; i++)
	{
		if (a[i] <= 90)
			b[a[i] - 65] += 1;
		else
			b[a[i] - 97] += 1;
	}

	int greatest = 0;
	for (int i = 0; i <= 25; i++)
	{
		if (b[greatest] < b[i])
			greatest = i;
	}

	for (int i = 0; i <= 25; i++)
	{
		if ((greatest != i) && (b[greatest] == b[i]))
		{
			greatest = (-2);
			break;
		}
	}
	printf("%c\n", greatest + 65);

	return 0;
}