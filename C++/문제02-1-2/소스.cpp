#include <iostream>

using namespace std;

void swap(int* &a, int* &b)
{
	int *temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	swap(ptr1, ptr2);

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	return 0;
}