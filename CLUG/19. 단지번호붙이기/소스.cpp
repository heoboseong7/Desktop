#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
	int x;
	int y;
}position;

int n;
int cnt = 0;
vector<vector<char>> map;
vector<vector<int>> check;
vector<int> house;
vector<position> pos;

void dfs(position start)
{
	int a = start.x;
	int b = start.y;
	check[a][b] = 1;
	for (int i = 0; i < 3; i++)
		switch (i)
		{
		case 0:
			if (b > 0 && check[a][b - 1] == 0)
				if (map[a][b - 1] == '1')
			{
				check[a][b - 1] = 1;
				house[cnt]++;
				position tmp = {a, b - 1};
				pos.push_back(tmp);
				dfs(pos.back());
			}
		case 1:
			if (check[a][b + 1] == 0)
				if (map[a][b + 1] == '1')
			{
				check[a][b + 1] = 1;
				house[cnt]++;
				position tmp = { a, b + 1};
				pos.push_back(tmp);
				dfs(pos.back());
			}
		case 2:
			if ((a < n - 1 ) && check[a + 1][b] == 0)
				if(map[a + 1][b] == '1')
			{
				check[a + 1][b] = 1;
				house[cnt]++;
				position tmp = { a + 1, b };
				pos.push_back(tmp);
				dfs(pos.back());
			}
		}
	return;
}

int main()
{
	cin >> n;
	map.resize(n);
	check.resize(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			char tmp;
			cin >> tmp;
			map[i].push_back(tmp);
			check[i].push_back(0);
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == '1')
				if (check[i][j] == 0)
				{
					house.push_back(1);
					position tmp = {i, j};
					dfs(tmp);
					cnt++;
				}

	sort(house.begin(), house.end());

	cout << cnt << endl;
	for (int i = 0; i < house.size(); i++)
		cout << house[i] << endl;

	return 0;
}