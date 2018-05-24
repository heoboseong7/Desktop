#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;
typedef struct
{
	vector<int> dst;
}inf;

queue<int> que;

inf *in;
int k = 0;
vector<int> prevn;
bool bfscheck[1000] = { false };
bool dfscheck[1000] = { false };
int dfsorder[1000];

void bfs(int start)
{
	bfscheck[start] = true;
	for (int i = 0; i < in[start].dst.size(); i++)
	{
		if (bfscheck[in[start].dst[i]] == false)
		{
			bfscheck[in[start].dst[i]] = true;
			que.push(in[start].dst[i]);
		}
	}

	cout << que.front() + 1 << ' ';

	que.pop();

	if (que.empty())
		return;
	else
	{
		bfs(que.front());
	}
}

void dfs(int start)
{
	dfscheck[start] = true;
	cout << start + 1 << ' ';
	sort(in[start].dst.begin(), in[start].dst.end());
	for (int i = 0; i < in[start].dst.size(); i++)
	{
		if (dfscheck[in[start].dst[i]] == false)
		{
			dfscheck[in[start].dst[i]] = true;
			prevn.push_back(in[start].dst[i]);
			dfs(prevn.back());
		}
	}
	return;
}

int main()
{
	int n, m, v;
	int tmp[2];

	cin >> n >> m >> v;
	in = new inf[n];
	for (int i = 0; i < m; i++)
	{
		cin >> tmp[0] >> tmp[1];
		in[tmp[0] - 1].dst.push_back(tmp[1] - 1);
		in[tmp[1] - 1].dst.push_back(tmp[0] - 1);
	}

	que.push(v - 1);
	dfs(v - 1);
	cout << endl;
	bfs(v - 1);

	return 0;
}