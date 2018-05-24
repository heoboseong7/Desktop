#include <stdio.h>
#include "MyFunc.h"

int main() {
	int a = 10;
	int b = 2;
	printf_s("if x = %d and y = %d, 2x+4y-8= %d\n", a, b, Func(a, b));
	return 0;
}