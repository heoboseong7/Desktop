#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 생년월일 구조체
struct birthday
{
	int year;
	int month;
	int day;
};

// 개인정보 구조체
struct personalstatement
{
	char name[30];
	struct birthday date;
	char gender[4];
	char address[30];
	char phonenumber[15];
};
// 이름 내림차순으로 qsort 함수를 통해 정렬할 때 이용할 비교함수
int compare_name(const void *a, const void *b)
{
	return (strcmp(((struct personalstatement*)b)->name , ((struct personalstatement*)a)->name));
}
// 생일 오름차 순으로 qsort 함수를 이용해 정렬할 때 이용할 비교함수
int compare_birth(const struct personalstatement *a, const struct personalstatement *b)
{
	if (a->date.year == b->date.year)
		if (a->date.month != b->date.month)
			return (a->date.month - b->date.month);
		else
			return (a->date.day - b->date.day);

	return (a->date.year - b->date.year);
}

int main()
{
	int n;
	struct personalstatement inf[10];
	printf("입력할 정보의 개수를 입력해 주세요 :");
	scanf("%d", &n);
	printf("이름, 생년월일, 성별, 주소, 전화번호 순서대로 입력해주세요 :\n");
	// n개의 개인정보를 입력받는다.
	for (int i = 0; i < n; i++)
	{
		scanf("%s", inf[i].name);
		scanf("%d %d %d", &inf[i].date.year, &inf[i].date.month, &inf[i].date.day);
		scanf("%s", inf[i].gender);
		scanf("%s", inf[i].address);
		scanf("%s", inf[i].phonenumber);
	}

	// 입력된 순서대로 출력
	printf("\n이름\t생년월일\t성별\t주소\t전화번호\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d년%d월%d일\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	// qsort 함수를 이용해 이름 내림차순으로 정렬 후 출력
	qsort(inf, n, sizeof(struct personalstatement), compare_name);
	printf("\n이름\t생년월일\t성별\t주소\t전화번호 - 이름 내림차순 정렬\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d년%d월%d일\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	// qsort 함수를 이용해 생일 오름차순으로 정렬 후 출력
	qsort(inf, n, sizeof(struct personalstatement), compare_birth);
	printf("\n이름\t생년월일\t성별\t주소\t전화번호- 생일 오름차순 정렬\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t%d년%d월%d일\t%s\t%-6s\t%s\n", inf[i].name, inf[i].date.year, inf[i].date.month, inf[i].date.day, inf[i].gender, inf[i].address, inf[i].phonenumber);
	}

	return 0;
}