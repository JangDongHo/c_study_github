#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10

void start_menu();
void cal_updown(int player, int computer, int *win);

void main()
{
	int value;				// ùȭ�鿡���� �Է°��� �����ϴ� �����Դϴ�.
	int player, computer;	// �÷��̾ ������ �Ͱ� ��ǻ���� ������ ���� �����ϴ� �����Դϴ�.
	int play = 0;			// �÷��̾ ������ Ƚ���� �����ϴ� �����Դϴ�.
	int rate[2] = { 0, 0 };	// �÷��̾��� ������ �����ϴ� �迭�Դϴ�. (��, ��)
	int win = 0;			// ������ �����ߴ��� Ȯ���ϴ� �����Դϴ�.

	// ù ����ȭ���� ����մϴ�.
	while (1)
	{
		start_menu();
		scanf("%d", &value);
		if (value < 1 || value > 3)
			continue;

		// 1��(�����ϱ�)�� �����ߴٸ�
		if (value == 1)
		{
			// 1~100 ������ ���� �� �ϳ��� �������� ���ϴ�.
			srand(time(NULL));
			computer = (rand() % 100) + 1;

			// ���� �����Դϴ�.
			while (play != COUNT)
			{
				// �÷��̾��� �������� �����ϴ� �����Դϴ�.
				printf("[%d]������: ", (COUNT - play));
				scanf("%d", &player);

				// ����� ����ϴ� �����Դϴ�.
				cal_updown(player, computer, &win);
				play++;

				// �����ߴٸ� ���� ������ Ż���մϴ�.
				if (win == 1)
					break;
			}
			// �õ�Ƚ�� �ȿ� �������� ���ߴٸ�
			if (win == 0)
			{
				printf("%d���� ������ ������ ������ �����ϼ̽��ϴ�. (��: %d)\n", play, computer);
				rate[1] += 1;
			}
			// �õ�Ƚ�� �ȿ� �����ߴٸ�
			else
			{
				printf("%d���� ���� ���� ������ �����߽��ϴ�. (��: %d)\n", play, computer);
				rate[0] += 1;
			}
			// ������ �ʱ�ȭ�մϴ�.
			play = 0;
			win = 0;
		}

		// 2��(����)�� �����ߴٸ�
		else if (value == 2)
			printf("����� ����: %d�� %d��\n", rate[0], rate[1]);

		// 3��(����)�� �����ߴٸ�
		else if (value == 3)
			exit(0);
	}
}

void start_menu()
{
	printf("==================\n");
	printf("1. �����ϱ�\n");
	printf("2. ����\n");
	printf("3. ����\n");
	printf("==================\n");
}

void cal_updown(int player, int computer, int *win)
{
	if (player == computer)
		*win = 1;
	else if (player > computer)
		printf("====== DOWN �Ʒ� �� ���� ======\n");
	else if (player < computer)
		printf("====== UP �� ߾ ���� ======\n");
}