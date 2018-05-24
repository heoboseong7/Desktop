#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int *lefttong;
int *righttong;
bool *check;
int sumleft = 0, sumright = 0;

int first(int tong[]);
int second(int tong[]);
int findmin(int tong[]);
int findmin2(int arr[], int n);
int checking(int tong[]);

int main()
{
	cin >> n;

	lefttong = new int[n];
	righttong = new int[n];
	check = new bool[n];

	int sum[4];

	for (int i = 0; i < n; i++)
	{
		cin >> lefttong[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> righttong[i];
	}
	//유효 여부 판단
	for (int i = 0; i < n; i++)
	{
		if (lefttong[i] > 0 && righttong[i] > 0)
			check[i] = true;
		else
			check[i] = false;
	}

	int k = 2;

	sum[0] = (first(lefttong) + second(righttong));
	sum[1] = (first(righttong) + second(lefttong));

	if (checking(lefttong) == 1)
	{
		sum[2] = second(lefttong) + 1;
		k++;
	}

	if (checking(righttong) == 1)
	{
		sum[3] = second(righttong) + 1;
		k++;
	}

	switch (findmin2(sum, k)) {
	case 0:
	{
		cout << first(lefttong) << endl;
		cout << second(righttong) << endl;
		break;
	}
	case 1:
	{
		cout << second(lefttong) << endl;
		cout << first(righttong) << endl;
		break;
	}
	case 2:
	{
		cout << sum[2] << endl;
		cout << 0 << endl;
		break;
	}
	case 3:
	{
		cout << 0 << endl;
		cout << sum[3] << endl;
		break;
	}
}

	delete []lefttong;
	delete []righttong;
	delete []check;

	return 0;
}

int first(int tong[])
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (check[i] == false)
		{
			sum += tong[i];
		}
	}
	return (sum + 1);
}

int second(int tong[])
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += tong[i];
	}

	return (sum - findmin(tong) + 1);
}

int findmin(int tong[])
{
	int min = 0;
	int k = 0;
	while (1)
	{
		if (check[k] == true)
		{
			min = tong[k];
			break;
		}
		else
			k++;
	}

	for (int i = k + 1; i < n; i++)
	{
		if (check[i] == true)
			if (min > tong[i])
				min = tong[i];
	}

	return min;
}

int findmin2(int arr[], int n)
{
	int min = 0;
	int i = 0;
	for (i = 1; i < n; i++)
	{
		if (arr[min] > arr[i])
			min = i;
	}

	return min;
}

int checking(int tong[])
{
	for (int i = 0; i < n; i++)
	{
		if (check[i] == true)
			if (tong[i] >= 2)
				return 1;
	}

	return 0;
}
/*
1. 유효 여부 판단 ex) 같은 색의 장갑이 반대 통에 있는지 없는지
2. 첫번째 통에서는 유효한 색의 장갑을 최소 1개씩 뽑을 수 있는 장갑의 수 and
3. 두번재 통에서는 유효한 장갑을 1개만 뽑는 경우의 수 or
장갑 개수 다 더하고 유효한 색 중 개수가 제일 작은것을 빼고 + 1
*/