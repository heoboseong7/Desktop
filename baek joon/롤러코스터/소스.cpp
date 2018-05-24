#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int row, column;
	scanf("%d %d", &row, &column);

	int **happy;

	happy = (int**)malloc(row);
	*happy = (int *)malloc(row * column);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			scanf("%d", happy[i] + j);

	if (row % 2 == 1 && column % 2 == 1)
}