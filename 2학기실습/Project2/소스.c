#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ENTER 0x0d
#define N 6

int main()
{
	char id[N][13] = { "wise","idle","timid","top","cool","pretty" };
	char pw[N][5] = { "w123","i123","t123","t456","c123","p123" };
	char input_pw[5] = "\0", input_id[13], ch;
	int index, i;
	int point[N] = { 2500,3500,1000,32000,22500,2000 };

	do
	{
		printf("-------------------------------\n");
		printf("1. 로그인하기\n");
		printf("2. 아이디로 정보찾기\n");
		printf("3. 최고 포인트 보기\n");
		printf("4. 아이디순 정렬\n");
		printf("5. 포인트순 정렬\n");
		printf("6. 그만하기\n");
		printf("-------------------------------\n");
		printf("◈원하는 메뉴를 입력하세요. (   )\b\b\b");
		scanf("%d", &index);
	} while ((index > 6) || (index < 1));

	switch (index)
	{
	case 1:
	{
		printf("로그인하세요\n\n");
		printf("----------------\n");
		printf("아 이 디 : ");
		scanf("%s", input_id);
		printf("비밀번호 : ");
		i = 0;

		/*do
		{
			ch = getch();
			input_pw[i] = ch;
			putch('*');
			i++;
		} while (ch != ENTER);
		*/
		while ((ch = getch()) != ENTER) {
			input_pw[i] = ch;
			putch('*');
			i++;
		}
		/*
		for (;;) {
		//ch = getch();
		scanf("%c", &ch);
		if (ch == ENTER)
		break;
		input_pw[i] = ch;
		putch('*');
		i++;
		}
		*/
		input_pw[i] = '\0';
		printf("\n입력한 비밀번호 %s\n", input_pw);
	}; break;
	}


	return 0;
}