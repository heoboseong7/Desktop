#include <stdio.h>

int main()
{
	int a[9];
	int temp = 0;

	for (int i = 0; i < 8; i++)
		scanf("%d", a + i);

	for (int i = 1; i < 8; i++)
	{
		if (a[i] == a[i - 1] + 1)
			temp++;
		else if (a[i] == a[i - 1] - 1)
			temp--;
		else
		{
			printf("mixed");
			break;
		}
	}
	if (temp == 7)
		printf("ascending");
	else if (temp == -7)
		printf("descending");

	return 0;
}