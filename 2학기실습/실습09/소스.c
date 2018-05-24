#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 0;

	while (strlen(argv[1]) - i)
		printf("%c", argv[1][strlen(argv[1]) - i++ - 1]);

	int n = argv[3][0] - 48;
	printf("   %d, %d\n", n, strlen(argv[2]));
	//rotate n
	for (i = 0; i < strlen(argv[2]); i++)
	{
		if (i + n  - 1 < strlen(argv[2]))
			printf("%c", argv[2][i + n - 1]);
		else
			printf("%c", argv[2][i + n - strlen(argv[2]) - 1]);
	}

	return 0;
}