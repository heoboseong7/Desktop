#include <iostream>
using namespace std;

int main()
{
	int money;
	while(1)
	{
		cout << "판매 금액을 만원 단위로 입력(-1 to end) : ";
		cin >> money;
		if (money == -1)
			break;
		cout << "이번 달 급여 : " << 50 + money * 0.12 << endl;
	}

	return 0;
}