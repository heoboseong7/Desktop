#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time
{
	int start;
	int end;
};

int compare(const void *a, const void *b)
{
	if ((((time*)a)->end > ((time*)b)->end))
		return 1;
	else if ((((time*)a)->end < ((time*)b)->end))
		return -1;
	else if ((((time*)a)->end == ((time*)b)->end))
		return ((((time*)a)->start - ((time*)b)->start));
}
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int end;
	int start;
	time a[100001];
	int cnt = 1;

	for (i = 0; i < n; i++)
		scanf("%d %d", &a[i].start, &a[i].end);

	qsort(a, n, sizeof(time), compare);

	end = a[0].end;
	start = a[0].end;
	for (i = 1; i < n; i++)
		if (a[i].start >= end)
		{
			end = a[i].end;
			cnt++;
		}

	printf("%d", cnt);

	return 0;
}