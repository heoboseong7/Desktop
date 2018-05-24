#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct box
{
	int sa;
	int sb;
	int ea;
	int eb;
};
int main()
{
	int space[500][500] = { 0 };
	int n;
	int sum = 0;
	box rec[101];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &rec[i].sa, &rec[i].sb, &rec[i].ea, &rec[i].eb);
	}

	for (int i = 0; i < n; i++)
		for (int j = rec[i].sa; j < rec[i].ea; j++)
			for (int k = rec[i].sb; k < rec[i].eb; k++)
				space[j][k] = 1;

	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			if (space[i][j] == 1)
				sum++;

	printf("%d", sum);

	return 0;
}