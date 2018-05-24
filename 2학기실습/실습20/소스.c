#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char name[100];
	char email[1000];
}information;

int main()
{
	char fname[] = "test.bin";
	information me;
	FILE *f;
	// 처음 값 표준 입력으로 입력받기
	fopen_s(&f, fname, "wb");
	printf("이름을 입력하세요 : ");
	fgets(me.name, 100, stdin);
	printf("email을 입력하세요 : ");
	fgets(me.email, 1000, stdin);

	//이진 파일에 쓰기
	fwrite(&me, sizeof(information), 1, f);

	//파일 닫기
	fclose(f);

	//저장된 이진 파일 다시 열어서 읽기
	printf("-----------------------------------------\n");
	printf("읽은 후 출력 출력\n");
	printf("-----------------------------------------\n");
	fopen_s(&f, fname, "rb");
	information test;
	fread(&test, sizeof(information), 1, f);
	printf("이름 : %s", test.name);
	printf("email : %s", test.email);

	fclose(f);

	return 0;
}