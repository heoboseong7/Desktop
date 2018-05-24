#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//add, sub mul div quot % abs rev

	if (strcmp(argv[3], "add") == 0)
		printf("%d\n", atoi(argv[4]) + atoi(argv[5]));
	else if (strcmp(argv[3], "sub") == 0)
		printf("%d\n", atoi(argv[4]) - atoi(argv[5]));
	else if (strcmp(argv[3], "mul") == 0)
		printf("%d\n", atoi(argv[4]) * atoi(argv[5]));
	else if (strcmp(argv[3], "div") == 0)
		printf("%lf\n", (atof(argv[4]) / atof(argv[5])));
	else if (strcmp(argv[3], "quot") == 0)
		printf("%d", atoi(argv[4]) / atoi(argv[5]));
	else if (strcmp(argv[3], "remain") == 0)
		printf("%d", atoi(argv[4]) % atoi(argv[5]));
	else if (strcmp(argv[3], "abs") == 0)
		if (atoi(argv[4]) >= 0)
			printf("%d", atoi(argv[4]));
		else
			printf("%d", -atoi(argv[4]));
	else if (strcmp(argv[3], "rev") == 0)
			printf("%d", -atoi(argv[4]));

	return 0;
}