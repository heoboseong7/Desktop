#include <iostream>

using namespace std;

int n;
int **map;
int *sum;
bool *check;

void dfs()
{

}
int main()
{
	cin >> n;

	*map = new int[n];
	check = new bool[n];
	sum = new int[n];

	for (int i = 0; i < n; i++)
	{
		*(map + i) = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		check[i] = false;
		sum[i] = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}




	delete[]map;
	return 0;
}