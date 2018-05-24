#include "header.h"

int main()
{
	int cnt = 0;
	int n;
	pnode head = NULL;
	pnode cur;

	printf("정수들을 입력해 주세요 : ");
	while (scanf("%d", &n) != EOF)
	{
		cur = create(n);
		head = append(head, cur);
		cnt++;
	}

	printf("입력된 자료의 개수\n%d\n", cnt);
	printf("역순으로 출력\n");
	reverse(head, cnt);
	printf("\n중간위치의 값\n");
	center(head, cnt);
	printf("입력된 순서대로 출력\n");
	print_fun(head);
	printf("\n홀수 번째 node를 삭제하고 출력\n");
	head = delete_odd(head, cnt);
	print_fun(head);
	printf("\n");

	return 0;
}