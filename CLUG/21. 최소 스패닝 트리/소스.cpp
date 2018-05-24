#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	int v1;
	int v2;
	int weight;
}information;

bool check[10000] = { false, };
int connected = 0;
vector<information> inf;
vector<vector<int>> Union;
int v, e;
long long int sum = 0;

bool compare(information a, information b)
{
	if (a.weight < b.weight)
		return 1;
	else
		return 0;
	return 0;
}


bool unioncheck(information start)
{
	int temp[2] = { 0 , 0 };
	int temp2[2] = { -1, -1 };
	for (int i = 0; i < Union.size(); i++)
	{
		for (int j = 0; j < Union[i].size(); j++)
		{
			if (Union[i][j] == start.v1)
			{
				temp[0]++;
				temp2[0] = i;
			}
			if (Union[i][j] == start.v2)
			{
				temp[1]++;
				temp2[1] = i;
			}
			if ((temp[1] + temp[0]) == 2)
			{
				return true;
			}
		}
		temp[0] = 0;
		temp[1] = 0;
	}

	//if (temp2[0] != -1 || temp2[1] != -1)
	//{
		if (temp2[0] != -1 && temp2[1] == -1)
		{
			Union[temp2[0]].push_back(start.v2);
			return false;
		}
		else if (temp2[1] != -1 && temp2[0] == -1)
		{
			Union[temp2[1]].push_back(start.v1);
			return false;
		}
		else if (temp2[0] != -1 && temp2[1] != -1)
		{
			int n, m;

			if (temp2[0] > temp2[1])
			{
				m = temp2[0];
				n = temp2[1];
			}
			else
			{
				n = temp2[0];
				m = temp2[1];
			}

			int k = Union[m].size();

			for (int i = 0; i < k; i++)
			{
				Union[n].push_back(Union[m].back());
				Union[m].pop_back();
			}
			//Union[m].clear();
			return false;
		}
	//}
		else if (temp2[0] == -1 && temp2[1] == -1)
		{
			Union.push_back(vector<int>());
			Union[Union.size() - 1].push_back(start.v1);
			Union[Union.size() - 1].push_back(start.v2);
			return false;
		}
}

void kruskal(information start)
{
	if (unioncheck(start) == true)
		return;

	if (check[start.v1] == false)
	{
		check[start.v1] = true;
		connected++;
	}
	if (check[start.v2] == false)
	{
		check[start.v2] = true;
		connected++;
	}
	sum += start.weight;
}

int main()
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		information temp;
		cin >> temp.v1 >> temp.v2 >> temp.weight;
		inf.push_back(temp);
	}

	sort(inf.begin(), inf.end(), compare);

	int i = 0;

	while (connected != v)
	{
		kruskal(inf[i++]);
	}

	cout << sum;

	return 0;
}