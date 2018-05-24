#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare(int a, int n, int *plug, int *tempplug, int ncnt)
{
	int tf = 0;

	for (int j = 0; j < ncnt; j++)
		if (tempplug[j] == a)
			return 0;
		else
			tf++;

	if (tf == ncnt)
		for (int i = 0; i < n; i++)
			if (plug[i] == a)
				return 0;

	return 1;
}

int main()
{
	int n, k;
	int cnt = 1;
	int ncnt = 0;
	int i, j = 0;
	int plug[21] = { 0 };
	int tempplug[21] = { 0 };
	int name[101] = { 0 };
	//int same[21]

	scanf("%d %d", &n, &k);

	for (i = 0; i < k; i++)
		scanf("%d", name + i);

	// 첫번째 플러그 값 받기
	plug[0] = name[0];

	// 초기값 n개 설정
	while (cnt != n)
	{
		for (i = 0; i < cnt; i++)
		{

			if (plug[i] != name[j])
			{
				plug[cnt++] = name[j++];
				break;
			}
			j++;
		}
	}

	for (i = j; i < k - n; i++)
	{
		for (; i < i + n; i++)
		{
			if (compare(name[i], n, plug, tempplug, ncnt))
			{
				tempplug[ncnt++] = name[i];
				cnt++;
			}
		}
		for (j = 0; j < n; j++)
		{
			plug[j] = name[i - n + j];
			tempplug[j] = 0;
		}
		ncnt = 0;
		i--;
	}

	printf("%d", cnt);

	return 0;
}