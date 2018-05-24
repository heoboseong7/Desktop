#include "header.h"

int main()
{
	int n, d;
	scanf("%d %d", &n, &d);

	int *a;
<<<<<<< HEAD
	a = (char*)malloc(sizeof(int) * n);
	_reverse(a, d, n);
=======
	a = (int*)malloc(sizeof(int) * n);
	gendata(a, n);
	printarr(a, n);
	rblock_swap(a, d, n);
>>>>>>> d53cfcf50613c923670aefc61fb40d68637f4d43
	printarr(a, n);
	free(a);
	return 0;
}