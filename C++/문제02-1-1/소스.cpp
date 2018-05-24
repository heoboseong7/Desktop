#include <iostream>

using namespace std;

void plusf(int &n)
{
	n++;
}

void reverse(int &n)
{
	n *= -1;
}

int main()
{
	int test = 100;
	plusf(test);
	cout << test << endl;
	reverse(test);
	cout << test << endl;
	return 0;
}