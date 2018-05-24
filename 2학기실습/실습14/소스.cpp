#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 1000
#define NUMERIC_TRUE 1
#define NUMERIC_FALSE 0
#define INTEGER_TRUE 1
#define INTEGER_FALSE 0

int IsNumeric(char *paramString);
int IsInteger(char *paramString);
char *String_Copy(char *dest, char *src);
char *Reverse_String(char *dest, char *src);
char *Encrpyt_String(char *dest, char *src, int nValue);
char *Rotate_String(char *dest, char *src, int nValue);

int main(int argc, char *argv[]) {
	/* Integer Declaration */
	int nValue = 0;
	int nString_count = 0;
	char sResultString[MAX_STRING_LENGTH] = { 0, };
	char *sNow_string, *sNow_encrypt_value, *sNow_rotate_value;

	/* Command Validation */
	if ((argc % 3) != 1) {
		fprintf(stderr, "Usage: exe <string1> <encrypt_value> <rotate_value> [<string2> <encrypt_value> <rotate_value>] ...\n");
		fprintf(stderr, "Value should be in (-1,000,000,000, 1,000,000,000) as an integer\n");
		system("PAUSE");
		return 1;
	}

	/* Iteration */
	while (argc > 1) {
		/* Print String ID */
		fprintf(stdout, "<String %d>\n", ++nString_count);

		/* Command Parameter Handling */
		argc -= 3;
		sNow_string = argv[nString_count * 3 - 2];
		sNow_encrypt_value = argv[nString_count * 3 - 1];
		sNow_rotate_value = argv[nString_count * 3];

		/* Initialization */
		memset(sResultString, 0, MAX_STRING_LENGTH);
		int length = 0;

		/* String Validation */
		while (sNow_string[++length] != '\0');

		if (length >= MAX_STRING_LENGTH) {
			fprintf(stderr, "Too long.\n\n");
			continue;
		}

		/* Value Validation */
		if (!IsNumeric(sNow_encrypt_value) || !IsNumeric(sNow_rotate_value)) {
			fprintf(stderr, "Error: Value should be a numeric.\n\n");
			continue;
		}
		if (!IsInteger(sNow_encrypt_value) || !IsInteger(sNow_rotate_value)) {
			fprintf(stderr, "Error: Value should be in (-1,000,000,000, 1,000,000,000) as an integer\n\n");
			continue;
		}
		int encrypt_value = atoi(sNow_encrypt_value);
		int rotate_value = atoi(sNow_rotate_value);

		/* String Copy */
		fprintf(stdout, "%-30s: %s\n", "Original String", sNow_string);
		fprintf(stdout, "%-30s: %s\n", "Copyed String", String_Copy(sResultString, sNow_string));

		/* Reverse String */
		fprintf(stdout, "%-30s: %s\n", "Reversed String", Reverse_String(sResultString, sNow_string));

		/* Encrypt String */
		fprintf(stdout, "%-30s: %s\n", "Encrypted String", Encrpyt_String(sResultString, sNow_string, encrypt_value));

		/* Rotate String */
		fprintf(stdout, "%-30s: %s\n", "Rotated String", Rotate_String(sResultString, sNow_string, rotate_value));

		/* Print New Line */
		fprintf(stdout, "\n");
	}

	/* Return */
	system("PAUSE");
	return 0;
}

int IsNumeric(char *paramString) {
	/* First character should be numeric or '-' sign */
	if ((paramString[0] < '0' || paramString[0] > '9') && paramString[0] != '-') return NUMERIC_FALSE;

	/* Other characters should be numeric */
	for (int i = 1; paramString[i]; i++) {
		if (paramString[i] < '0' || paramString[i] > '9') return NUMERIC_FALSE;
	}
	return NUMERIC_TRUE;
}

int IsInteger(char *paramString) {
	int nLength = 0;

	/* Get String Length */
	while (paramString[++nLength]);

	/* Sign Handling */
	if (paramString[0] == '-') nLength--;

	/* Same or over 1 billion is regarded as long type */
	if (nLength >= 10) return INTEGER_FALSE;
	return INTEGER_TRUE;
}

char *String_Copy(char *dest, char *src) {
	int i = 0;

	/* String Copy */
	while (dest[i] = src[i++]);
	return dest;
}

char *Reverse_String(char *dest, char *src) {
	int nLength = 0;

	/* Get String Length */
	while (src[++nLength]);

	/* Reverse String */
	for (int i = 0; i < nLength; i++) {
		dest[nLength - 1 - i] = src[i];
	}

	/* End of String */
	dest[nLength] = '\0';

	/* Return */
	return dest;
}

char *Encrpyt_String(char *dest, char *src, int nValue) {
	/* Negative Value Handling */
	while (nValue < 0) {
		nValue += 26;
	}

	/* Extended Value Handling */
	while (nValue >= 26) {
		nValue %= 26;
	}

	/* Encrypt Caesar */
	int i = 0;
	int nBasement = 0;
	for (i = 0; src[i]; i++) {
		/* Non-alphabet Handling */
		if (src[i] < 'A' || (src[i] > 'Z' && src[i] < 'a') || src[i] >'z') {
			dest[i] = src[i];
			continue;
		}
		/* Encrypt */
		nBasement = (src[i] < 'a') ? 'A' : 'a';
		dest[i] = (src[i] + nValue - nBasement) % 26 + nBasement;
	}

	/* End of String */
	dest[i] = '\0';

	/* Return */
	return dest;
}

char *Rotate_String(char *dest, char *src, int nValue) {
	int nLength = 0;

	/* Get String Length */
	while (src[++nLength]);

	/* Value Handling */
	while (nValue < 0) {
		nValue %= nLength;
		nValue += nLength;
	}

	/* Rotate */
	for (int i = 0; i < nLength; i++) {
		dest[(i + nValue) % nLength] = src[i];
	}

	/* End of String */
	dest[nLength] = '\0';

	/* Return */
	return dest;
}