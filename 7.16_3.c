#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_choice(int player, int computer);
void check_win(int player, int computer, int rate[], int *lose);

void main()
{
	int player, computer;	// �÷��̾�� ��ǻ�Ͱ� � ���� �´��� �����ϴ� �����Դϴ�.
	int rate[2] = { 0, 0 };	// �·��� �����ϴ� �迭�Դϴ�. (��, ��)
	int lose = 0;				// �÷��̾ ������ üũ�ϴ� �����Դϴ�.

	while (lose == 0)
	{
		// �÷��̾ � ���� ���� �����ϴ� �����Դϴ�.
		printf("������ 1, ������ 2, ���� 3: ");
		scanf("%d", &player);
		//

		// ��ǻ�Ͱ� � ���� ���� �����ϴ� �����Դϴ�.
		srand(time(NULL));
		computer = (rand() % 3) + 1;

		// � ���� ���� ����ϴ� �����Դϴ�.
		print_choice(player, computer);

		// ����� ó���ϴ� �����Դϴ�.
		check_win(player, computer, rate, &lose);
	}
	// ������ ����� ����ϴ� �����Դϴ�.
	printf("������ ���: %d��, %d��", rate[0], rate[1]);
}

void print_choice(int player, int computer)
{
	if (player == 1)		// �÷��̾ � ���� ���� ����ϴ� �����Դϴ�.
		printf("����� ���� ����, ");
	else if (player == 2)
		printf("����� ���� ����, ");
	else if (player == 3)
		printf("����� �� ����, ");

	if (computer == 1)		// ��ǻ�Ͱ� � ���� ���� ����ϴ� �����Դϴ�.
		printf("��ǻ�ʹ� ���� ����, ");
	else if (computer == 2)
		printf("��ǻ�ʹ� ���� ����, ");
	else if (computer == 3)
		printf("��ǻ�ʹ� �� ����, ");
}

void check_win(int player, int computer, int rate[], int *lose)
{
	// �÷��̾�� ��ǻ�Ͱ� ���� ���� ���� ���
	if (player == computer)
	{
		printf("�����ϴ�!");
		rate[1] += 1;
	}
	// �÷��̾ ������ ���� ���
	else if (player == 1)
	{
		if (computer == 2)
		{
			printf("����� �̰���ϴ�!");
			rate[0] += 1;
		}
		else if (computer == 3)
		{
			printf("����� �����ϴ�!");
			*lose = 1;
		}
	}
	// �÷��̾ ������ ���� ���
	else if(player == 2)
	{
		if (computer == 3)
		{
			printf("����� �̰���ϴ�!");
			rate[0] += 1;
		}
		else if (computer == 1)
		{
			printf("����� �����ϴ�!");
			*lose = 1;
		}
	}
	// �÷��̾ ���� ���� ���
	else if (player == 3)
	{
		if (computer == 1)
		{
			printf("����� �̰���ϴ�!");
			rate[0] += 1;
		}
		else if (computer == 2)
		{
			printf("����� �����ϴ�!");
			*lose = 1;
		}
	}
	printf("\n");
}