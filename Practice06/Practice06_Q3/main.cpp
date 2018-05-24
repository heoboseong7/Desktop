#include <stdio.h>
#include "Discrement.h"

int main() {
	int a = 10, b = 20, c = 7;
	printf_s("if a = %d, b = %d and C = %d, Discrement of ax^2+bx+c is %d\n", a, b, c, Disc(a, b, c));
	return 0;
}