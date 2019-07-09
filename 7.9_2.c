#include <stdio.h>

void main()
{
	int box[10];		// 초기 배열입니다.
	int show_box[10];	// 변형될 배열입니다.

	printf("총 10개의 숫자 입력\n");	// 정수 10개를 입력받습니다.
	for (int i = 0; i < 10; i++)
	{
		printf("입력: ");
		scanf("%d", &box[i]);
	}

	for (int i = 0, k = 9, j = 0; j<10; j++)	// i값=인덱스0부터(배열 처음부터), k값=인덱스9부터(배열 끝부터), j값=포인터
	{
		if (box[j] % 2 != 0)		// 홀수이면
		{
			show_box[i] = box[j];
			i++;
		}
		else
		{
			show_box[k] = box[j];
			k--;
		}
	}

	printf("배열 요소의 출력: ");	// 결과값 출력
	for (int q = 0; q < 10; q++)
		printf("%d ", show_box[q]);
}