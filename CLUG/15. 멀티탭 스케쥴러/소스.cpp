#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a[], int n)
{
	int max = 0;
	int maxt = a[0];
	for (int i = 1; i < n; i++)
		if (maxt < a[i])
		{
			maxt = a[i];
			max = i;
		}
	return max;
}

int find(int* name, int n, int plug, int k)
{
	int min;
		for (int i = n; i < k; i++)
			if (plug == name[i])
				return i;

	return 200;
}

int cmp(int a, int plug[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a == plug[i])
			return 0;
	}
	return 1;
}

int main()
{
	int n, k;
	int cnt = 1;
	int i, j = 0;
	int plug[101] = { 0 };
	int nplug[101] = { 0 };

	scanf("%d %d", &n, &k);

	int name[101] = { 0 };
	for (i = 0; i < k; i++)
		scanf("%d", name + i);

	// 첫번째 플러그 값 받기
	plug[0] = name[0];

	while (cnt != n)
	{
		if (cmp(name[j], plug, cnt))
		{
			plug[cnt] = name[j];
			cnt++;
		}
		j++;
	}

	//카운트 초기화
	cnt = 0;

	for (i = j; i < k; i++)
	{
		if (cmp(name[i], plug, n))
		{
			for (int m = 0; m < n; m++)
			{
				nplug[m] = find(name, i + 1, plug[m], k);
			}

			plug[max(nplug, n)] = name[i];
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}