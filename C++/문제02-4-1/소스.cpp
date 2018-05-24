#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char line[101] = "test1";
	cout << strlen(line) << endl;
	strcat(line, "test2");
	cout << line << endl;
	strcpy(line, "test3");
	cout << line << endl;
	cout << strcmp(line, "test3") << endl;
	cout << line << endl;

	return 0;
}