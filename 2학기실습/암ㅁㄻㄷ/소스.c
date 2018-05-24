#include <stdio.h>

int main() {
	char c = getchar();
	printf("CHAR\tHEX\tDEC\tOCT\n");
	for (int i = 0; i < 5; i++) 
		printf("%c\tX%x\t%d\t%o\n", c + i, c + i, c + i, c + i);
	
	return 0;
}