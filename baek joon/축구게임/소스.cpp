#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct
{
	int win;
	int lose;
}score;

bool compare(score a, score b)
{
	if (a.win > b.win)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	int sum = 0;
	int cmp = 0;
	cin >> n;
	score *a = new score[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].win;
		a[i].lose = 0;
	}

	for (int i = 0; i < n; i++)
	{
		sum += i;
		cmp += a[i].win;
	}

	if (sum != cmp)
	{
		cout << -1;
		return 0;
	}

	sort(a, a + n, compare);

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i].win; j++)
			a[n - 1 - j].lose += 1;

		if (a[i].win != n - 1 - a[i].lose)
		{
			cout << -1;
			return 0;
		}
	}

	cout << 1;
	delete []a;
	return 0;
}