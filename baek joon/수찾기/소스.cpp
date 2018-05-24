#include <iostream>
#include <algorithm>

using namespace std;

int arrn[100001] = { 0, };
int arrm[100001] = { 0, };

int search(int left, int right, int ans) {
	int center = (left + right) / 2;

	if (left <= right) {
		if (arrn[center] == ans) {
			return 1;
		}
		else if (arrn[center] > ans) {
			return search(left, center - 1, ans);
		}
		else if (arrn[center] < ans) {
			return search(center + 1, right, ans);
		}
	}
	else
		return 0;
}
int main() {
	int n, m;

	cin >> n;
	
	for (int i = 0; i < n; i++) 
		cin >> arrn[i];

	cin >> m;

	for (int i = 0; i < m; i++) 
		cin >> arrm[i];
	
	sort(arrn, arrn + n);

	for (int i = 0; i < m; i++)
		cout << search(0, n - 1, arrm[i]) << '\n';

	return 0;
}