#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	int sum = 0;
	double avg = 0;
	double stddvi;
	double sum2 = 0;
	scanf("%d", &n);

	int *score = (int *)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", score + i);
		sum += score[i];
	}
	avg = sum / n;

	for (int i = 0; i < n; i++)
	{
		sum2 += pow(score[i] - avg, 2);
	}

	printf("합 : %d\n", sum);
	printf("평균 : %lf\n", avg);
	printf("표준편차 : %lf\n", sqrt(sum2 / n));

	free(score);
	return 0;
}