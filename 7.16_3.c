#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_choice(int player, int computer);
void check_win(int player, int computer, int rate[], int *lose);

void main()
{
	int player, computer;	// 플레이어와 컴퓨터가 어떤 것을 냈는지 저장하는 변수입니다.
	int rate[2] = { 0, 0 };	// 승률을 저장하는 배열입니다. (승, 무)
	int lose = 0;				// 플레이어가 졌는지 체크하는 변수입니다.

	while (lose == 0)
	{
		// 플레이어가 어떤 것을 낼지 결정하는 구문입니다.
		printf("바위는 1, 가위는 2, 보는 3: ");
		scanf("%d", &player);
		//

		// 컴퓨터가 어떤 것을 낼지 결정하는 구문입니다.
		srand(time(NULL));
		computer = (rand() % 3) + 1;

		// 어떤 것을 낸지 출력하는 구문입니다.
		print_choice(player, computer);

		// 결과를 처리하는 구문입니다.
		check_win(player, computer, rate, &lose);
	}
	// 게임의 결과를 출력하는 구문입니다.
	printf("게임의 결과: %d승, %d무", rate[0], rate[1]);
}

void print_choice(int player, int computer)
{
	if (player == 1)		// 플레이어가 어떤 것을 낸지 출력하는 구문입니다.
		printf("당신은 바위 선택, ");
	else if (player == 2)
		printf("당신은 가위 선택, ");
	else if (player == 3)
		printf("당신은 보 선택, ");

	if (computer == 1)		// 컴퓨터가 어떤 것을 낸지 출력하는 구문입니다.
		printf("컴퓨터는 바위 선택, ");
	else if (computer == 2)
		printf("컴퓨터는 가위 선택, ");
	else if (computer == 3)
		printf("컴퓨터는 보 선택, ");
}

void check_win(int player, int computer, int rate[], int *lose)
{
	// 플레이어와 컴퓨터가 같은 것을 냈을 경우
	if (player == computer)
	{
		printf("비겼습니다!");
		rate[1] += 1;
	}
	// 플레이어가 바위를 냈을 경우
	else if (player == 1)
	{
		if (computer == 2)
		{
			printf("당신이 이겼습니다!");
			rate[0] += 1;
		}
		else if (computer == 3)
		{
			printf("당신이 졌습니다!");
			*lose = 1;
		}
	}
	// 플레이어가 가위를 냈을 경우
	else if(player == 2)
	{
		if (computer == 3)
		{
			printf("당신이 이겼습니다!");
			rate[0] += 1;
		}
		else if (computer == 1)
		{
			printf("당신이 졌습니다!");
			*lose = 1;
		}
	}
	// 플레이어가 보를 냈을 경우
	else if (player == 3)
	{
		if (computer == 1)
		{
			printf("당신이 이겼습니다!");
			rate[0] += 1;
		}
		else if (computer == 2)
		{
			printf("당신이 졌습니다!");
			*lose = 1;
		}
	}
	printf("\n");
}