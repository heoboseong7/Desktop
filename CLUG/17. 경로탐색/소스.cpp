#include <iostream>
#include <vector>
using namespace std;

int ary[100][100];
int check[100][100] = { 0 };
int n;
int k;
vector<int> prevn;

/*
void check_Init()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			check[i][j] = 0;
}
*/

void dfs(int start)
{
	for (int i = 0; i < n; i++)
	{
		if (ary[start][i] == 1)
			if(check[k][i] == 0)
			{
				prevn.push_back(start);
				check[k][i] += 1;
				dfs(i);
			}
	}
	return;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> ary[i][j];

	for (k = 0; k < n; k++)
		dfs(k);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << check[i][j] << ' ';
		cout << endl;
	}
	return 0;
}