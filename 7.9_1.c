#include <stdio.h>

void odd(int box[]);	// Ȧ���� �����س��� �Լ��Դϴ�.
void even(int box[]);	// ¦���� �����س��� �Լ��Դϴ�.

void main()
{
	int box[10];

	printf("�� 10���� ���� �Է�\n");
	for (int i = 0; i < 10; i++)	// 10���� ������ �Է¹޽��ϴ�.
	{
		printf("�Է�: ");
		scanf("%d", &box[i]);
	}
	odd(box);	// Ȧ�� ���� ����
	even(box);	// ¦�� ���� ����
}

void odd(int box[])
{
	printf("Ȧ�� ���: ");
	for (int i = 0; i < 10; i++)
	{
		if (box[i] % 2 != 0)		// Ȧ���̸�
		{
			printf("%d, ", box[i]);
		}
	}
	printf("\n");
}

void even(int box[])
{
	printf("¦�� ���: ");
	for (int i = 0; i < 10; i++)
	{
		if (box[i] % 2 == 0)		// ¦���̸�
		{
			printf("%d, ", box[i]);
		}
	}
	printf("\n");
}