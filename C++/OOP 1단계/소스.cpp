#include <iostream>
#include <cstring>

using namespace std;

void makeacc();
void depositmoney();
void withdrawmoney();
void showallaccinfo();

typedef struct
{
	int accid;
	int balance;
	char name[20];
}acc;

acc account[100];
int accn = 0;

int main()
{
	int choice;
	while (1)
	{
		cout << "----Menu----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			makeacc();
			break;
		case 2:
			depositmoney();
			break;
		case 3:
			withdrawmoney();
			break;
		case 4:
			showallaccinfo();
			break;
		case 5:
			return 0;
		default :
			cout << "제대로 된 값을 입력해 주세요." << endl;
		}
		cout << endl;
	}
	return 0;
}

void makeacc()
{
	cout << "[계 좌 개 설]" << endl;
	cout << "계좌 ID : ";
	cin >> account[accn].accid;
	cout << "이름 : ";
	cin >> account[accn].name;
	cout << "입금액 : ";
	cin >> account[accn].balance;

	accn++;
}

void depositmoney()
{
	int cmpid;
	int money;
	int i;
	cout << "[입   금]" << endl;
	cout << "계좌ID : ";
	cin >> cmpid;
	for(i = 0; i <  accn; i++)
		if (cmpid == account[i].accid)
			break;
	if (i == accn + 1)
	{
		cout << "유효하지 않은 ID 입니다." << endl;
		return;
	}

	cout << "입금액 : ";
	cin >> money;
	account[i].balance += money;
}

void withdrawmoney()
{
	int i;
	int cmpid;
	int money;
	cout << "[출   금]" << endl;
	cout << "계좌ID : ";
	cin >> cmpid;
	for (i = 0; i < accn; i++)
		if (cmpid == account[i].accid)
			break;
	if (i == accn + 1)
	{
		cout << "유효하지 않은 ID 입니다." << endl;
		return;
	}
	cout << "출금액 : ";
	cin >> money;
	if (account[i].balance < money)
		cout << "잔액 부족" << endl;
	else
	{
		account[i].balance -= money;
		cout << "출금 완료" << endl;
	}
}

void showallaccinfo()
{
	for (int i = 0; i < accn; i++)
	{
		cout << "계좌ID : " << account[i].accid << endl;
		cout << "이 름  : " << account[i].name << endl;
		cout << "잔 액  : " << account[i].balance << endl;
	}
}