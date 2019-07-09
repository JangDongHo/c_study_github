#include <stdio.h>

void odd(int box[]);	// 홀수를 구분해내는 함수입니다.
void even(int box[]);	// 짝수를 구분해내는 함수입니다.

void main()
{
	int box[10];

	printf("총 10개의 숫자 입력\n");
	for (int i = 0; i < 10; i++)	// 10개의 정수를 입력받습니다.
	{
		printf("입력: ");
		scanf("%d", &box[i]);
	}
	odd(box);	// 홀수 구문 실행
	even(box);	// 짝수 구문 실행
}

void odd(int box[])
{
	printf("홀수 출력: ");
	for (int i = 0; i < 10; i++)
	{
		if (box[i] % 2 != 0)		// 홀수이면
		{
			printf("%d, ", box[i]);
		}
	}
	printf("\n");
}

void even(int box[])
{
	printf("짝수 출력: ");
	for (int i = 0; i < 10; i++)
	{
		if (box[i] % 2 == 0)		// 짝수이면
		{
			printf("%d, ", box[i]);
		}
	}
	printf("\n");
}