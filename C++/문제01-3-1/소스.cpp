#include <iostream>
using namespace std;

int boxvolume(int length)
{
	int width = 1, height = 1;
	return length * width * height;
}

int boxvolume(int length, int width)
{
	int height = 1;
	return length * width * height;
}

int boxvolume(int length, int width, int height)
{
	return length * width * height;
}

int main()
{
	cout << "[3, 3, 3] : " << boxvolume(3, 3, 3) << endl;
	cout << "[3, 3, D] : " << boxvolume(3, 3) << endl;
	cout << "[3, D, D] : " << boxvolume(3) << endl;

	return 0;
}