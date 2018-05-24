#include "header.h"

int main()
{
	int n, d;
	char *a = NULL;
	a = gendata(a, &n, &d);
	printf("%d %d\n", n, d);
	//printarr(a, n);
	clock_t start = clock();
	_reverse(a, d, n);
	printf("소요 시간 : %.10f\n", (float)(clock() - start) / CLOCKS_PER_SEC);
	//printarr(a, n);
	free(a);
	return 0;
}