#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = n; i <= m; i++) {
		bool check = true;
		if (i == 1)
			continue;
		for(int j = 2; j <= sqrt(i); j++) {
			if(i % j == 0) {
				check = false;
				break;
			}
		}
		if(check)
			cout << i << '\n';
	}

	return 0;
}