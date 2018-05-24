#include <stdio.h>
struct birthday
{
	int year;
	int month;
	int day;
};
struct personalstatement
{
	char name[30];
	struct birthday date;
	char gender[4];
	char address[30];
	int phonenumber;
};
int main()
{
	struct personalstatement inf = { "허보성",{ 1998, 12, 9 }, "남", "충청북도 충주시 중원대로 3379", 1030048506 };
	printf("이름 : %s\n", inf.name);
	printf("생년월일 : %d년 %d월 %d일\n", inf.date.year, inf.date.month, inf.date.day);
	printf("성별 : %s\n", inf.name);
	printf("주소 : %s\n", inf.address);
	printf("전화번호 : 0%d\n\n", inf.phonenumber);

	printf("이름\t생년월일\t성별\t주소\t\t\t\t전화번호\n");
	printf("%s\t%d-%d-%d\t%s\t%s\t0%d", inf.name, inf.date.year, inf.date.month, inf.date.day, inf.gender, inf.address, inf.phonenumber);

	return 0;
}