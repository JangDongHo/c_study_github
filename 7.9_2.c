#include <stdio.h>

void main()
{
	int box[10];		// �ʱ� �迭�Դϴ�.
	int show_box[10];	// ������ �迭�Դϴ�.

	printf("�� 10���� ���� �Է�\n");	// ���� 10���� �Է¹޽��ϴ�.
	for (int i = 0; i < 10; i++)
	{
		printf("�Է�: ");
		scanf("%d", &box[i]);
	}

	for (int i = 0, k = 9, j = 0; j<10; j++)	// i��=�ε���0����(�迭 ó������), k��=�ε���9����(�迭 ������), j��=������
	{
		if (box[j] % 2 != 0)		// Ȧ���̸�
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

	printf("�迭 ����� ���: ");	// ����� ���
	for (int q = 0; q < 10; q++)
		printf("%d ", show_box[q]);
}