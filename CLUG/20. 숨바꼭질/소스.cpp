#include <iostream>
#include <queue>
using namespace std;

bool check[100001] = { false };
int cnt[100001] = { 0 };
int n, k;
queue<int> que;
int bfs(int start)
{
	if (start == k)
		return 1;

	if (start < 100000 && check[start + 1] == false)
	{
		que.push(start + 1);
		check[start + 1] = true;
		cnt[start + 1] = cnt[start] + 1;
	}
	if (start > 0 && check[start - 1] == false)
	{
		que.push(start - 1);
		check[start - 1] = true;
		cnt[start - 1] = cnt[start] + 1;
	}
	if ((start * 2) <= 100000 && check[start * 2] == false)
	{
		que.push(start * 2);
		check[start * 2] = true;
		cnt[start * 2] = cnt[start] + 1;
	}

	que.pop();

	return 0;
}
int main()
{
	cin >> n >> k;
	que.push(n);

	if (n == k)
	{
		cout << 0;
		return 0;
	}
	while (1)
	{

		if (bfs(que.front()) == 1)
		{
			cout << cnt[que.front()];
			break;
		}
	}

	return 0;
}