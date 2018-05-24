#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define inf 1000000000;
using namespace std;
int val[17][17];
int dp[17][1 << 16];
int n;


int go(int state, int now) {
	if ((state & 1) && state != (1 << n) - 1)
		return inf;
	if (state == (1 << n) - 1) 
		return 0;
	int&ret = dp[now][state];

	if (ret != -1) 
		return ret;

	ret = inf;

	for (int i = 0; i < n; i++) {
		if (val[now][i]>0 && !(state&(1 << i))) {
			ret = min(ret, go(state | (1 << i), i) + val[now][i]);
		}
	}
	return ret;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &val[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", go(0, 0));
}