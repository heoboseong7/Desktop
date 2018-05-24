#include <stdio.h>

int main()
{
	int length;
	int bin[7] = { 0 };
	int cnt = 0;
	scanf("%d", &length);

	for (int i = 0; i < 7; i++)
		if ((length >> i) & 1)
			bin[i] = 1;

	for (int i = 0; i < 7; i++)
		if (bin[i] == 1)
			cnt++;

	printf("%d", cnt);

	return 0;
}