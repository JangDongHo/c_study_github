#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10

void start_menu();
void cal_updown(int player, int computer, int *win);

void main()
{
	int value;				// 첫화면에서의 입력값을 저장하는 변수입니다.
	int player, computer;	// 플레이어가 제출한 것과 컴퓨터의 무작위 수를 저장하는 변수입니다.
	int play = 0;			// 플레이어가 도전한 횟수를 저장하는 변수입니다.
	int rate[2] = { 0, 0 };	// 플레이어의 전적을 저장하는 배열입니다. (승, 패)
	int win = 0;			// 추측에 성공했는지 확인하는 변수입니다.

	// 첫 게임화면을 출력합니다.
	while (1)
	{
		start_menu();
		scanf("%d", &value);
		if (value < 1 || value > 3)
			continue;

		// 1번(게임하기)를 선택했다면
		if (value == 1)
		{
			// 1~100 사이의 숫자 중 하나를 무작위로 고릅니다.
			srand(time(NULL));
			computer = (rand() % 100) + 1;

			// 게임 구문입니다.
			while (play != COUNT)
			{
				// 플레이어의 추측값을 결정하는 구문입니다.
				printf("[%d]추측값: ", (COUNT - play));
				scanf("%d", &player);

				// 결과를 계산하는 구문입니다.
				cal_updown(player, computer, &win);
				play++;

				// 성공했다면 게임 구문을 탈출합니다.
				if (win == 1)
					break;
			}
			// 시도횟수 안에 성공하지 못했다면
			if (win == 0)
			{
				printf("%d번의 도전을 했지만 추측에 실패하셨습니다. (값: %d)\n", play, computer);
				rate[1] += 1;
			}
			// 시도횟수 안에 성공했다면
			else
			{
				printf("%d번의 도전 끝에 추측에 성공했습니다. (값: %d)\n", play, computer);
				rate[0] += 1;
			}
			// 게임을 초기화합니다.
			play = 0;
			win = 0;
		}

		// 2번(전적)을 선택했다면
		else if (value == 2)
			printf("당신의 전적: %d승 %d패\n", rate[0], rate[1]);

		// 3번(종료)을 선택했다면
		else if (value == 3)
			exit(0);
	}
}

void start_menu()
{
	printf("==================\n");
	printf("1. 게임하기\n");
	printf("2. 전적\n");
	printf("3. 종료\n");
	printf("==================\n");
}

void cal_updown(int player, int computer, int *win)
{
	if (player == computer)
		*win = 1;
	else if (player > computer)
		printf("====== DOWN 아래 下 した ======\n");
	else if (player < computer)
		printf("====== UP 위 上 うえ ======\n");
}