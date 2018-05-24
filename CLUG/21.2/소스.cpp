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

bool check[10001] = { false, };
int connected = 0;
vector<information> inf;
int Union[10001] = { (-1), };
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

int findparent(int n)
{
	if (Union[n] == -1)
		return n;
	else
		return findparent(Union[n]);
}

void unify(int n, int m)
{
	Union[n] = m;
}

int isunion(int n, int m)
{
	if (findparent(n) == findparent(m))
		return 1;
	// °°À»½Ã 1
	else
		return 0;
}

int checkfun(bool n, bool m)
{
	if (n == false)
	{
		if (m == false)
			return 1;
		else
			return 2;
	}
	else
	{
		if (m == false)
			return 3;
		else
			return 4;
	}
}

void kruskal(information start)
{
	switch (checkfun(check[start.v1], check[start.v2]))
	{
	case 1:
		{
			check[start.v1] = true;
			check[start.v2] = true;
			connected++;
			unify(start.v2, start.v1);
			sum += start.weight;
			return;
		}
	case 3:
		{
			check[start.v2] = true;
			connected++;
			unify(start.v2, start.v1);
			sum += start.weight;
			return;
		}
	case 2:
		{
			check[start.v1] = true;
			connected++;
			unify(start.v1, start.v2);
			sum += start.weight;
			return;
		}
	case 4:
		{
			if (isunion(start.v1, start.v2) == 0)
			{
				unify(findparent(start.v2), findparent(start.v1));
				sum += start.weight;
				connected++;
			}
			return;
		}
	}
}



int main()
{
	cin >> v >> e;

	for (int i = 0; i < 10001; i++)
	{
		Union[i] = -1;
	}
	for (int i = 0; i < e; i++)
	{
		information temp;
		cin >> temp.v1 >> temp.v2 >> temp.weight;
		inf.push_back(temp);
	}

	sort(inf.begin(), inf.end(), compare);

	int i = 0;
	while (connected != (v - 1))
	{
		kruskal(inf[i++]);
	}

	cout << sum;

	return 0;
}