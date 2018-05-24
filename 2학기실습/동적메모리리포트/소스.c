#include <stdio.h>
#include <stdlib.h>

int main()
{

	int cnt = 0;
	int k;
	printf("초기 사이즈 입력 : ");
	scanf("%d", &k);
	char *test = (char*)malloc(k);
	int sum = 0;
	while (1)
	{
		//사이즈를 더이상 줄일 수 없을 때 반복문을 빠져나온다.
		if (k == 0)
			break;
		// 메모리 할당이 실패했을 경우 사이즈를 반으로 줄인다.
		if (test == NULL)
		{
			k = k / 2;
			printf("동적메모리 할당 요청 거절, 사이즈를 반으로 줄임\n");
			cnt = 0;
		}
		// 메모리 할당이 제대로 됐을 경우 현재의 1개당 사이즈와 해당 사이즈로 할당받은 개수를 출력하고
		// 변수 sum에 해당 사이즈를 더하여 할당된 총 메모리 값을 구한다.
		else
		{
			sum += k;
			printf("현재 1개의 사이즈 : %d Bytes  해당 사이즈로 할당받은 개수 : %d 개 \n", k, ++cnt);
		}
		test = (char*)malloc(k);
	}
	printf("더이상 줄일 수 없음\n");
	printf("지금까지 할당받은 메모리의 합 : %d Bytes\n", sum);
	free(test);
	return 0;
}