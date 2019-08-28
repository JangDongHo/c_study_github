#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct user
{
	char name[20];
	char id[15];
	char pw[15];
	int rate[4];
}USER;

int menu();	// �޴��� ���õ� �Լ�
void register_login(USER user[10], int* index, int* player);	// ȸ������&�α��� �Լ�
void rate_user(USER user[10], int player, int index);	// ����, ��� �Լ�
//void main_game(USER user[10], int player);	// ���� �Լ�
void file_load(FILE* fp, USER user[10], int* index);	// ���� �ҷ�����
void file_save(USER user[10], int index);	// ���� �����ϱ�

int main()
{
	USER user[10];
	for (int i = 0; i < 10; i++) {      //��,��,��,���� 0���� �ʱ�ȭ�մϴ�.
		for (int j = 0; j < 4; j++) {
			user[i].rate[j] = 0;
		}
	}

	int index;	// ȸ������ �� ������ ���� Ȯ���ϴ� �����Դϴ�.
	int player = -1;	// �α��ε� ������ �ε����� Ȯ���ϴ� �����Դϴ�. (-1�Ͻ�, ��α��� ����)

	// ������ ���� ������ �Ǵ��ϴ� �����Դϴ�.
	FILE* fp;
	fp = fopen("data.dat", "rb");
	if (fp == NULL)
	{
		// ���� ���� �� ������ �����ϴ� �����Դϴ�.
		printf("FILE DOWNLOAD (���� 1ȸ)\n");
		fp = fopen("data.dat", "wb");
		index = -1;	// index ���� -1�� �ʱ�ȭ�մϴ�.
		printf("[TEST] ���� �ε�����: %d\n", index);
	}
	else
	{
		file_load(fp, user, &index);	// index ���� ���� ����ŭ �����մϴ�.
	}
	fclose(fp);

	// �޴��� �����ϴ� �����Դϴ�.
	while (1)
	{
		switch ((menu()))
		{
		case 1: {register_login(user, &index, &player); break; }
		//case 2: {game_user(user, player); break; }
		case 3: {rate_user(user, player, index); break; }
		case 4: {file_save(user, index); return 0; }
		}
	}
}

int menu()
{
	int select;
	printf("��������������������\n");
	printf("1. ȸ������&�α���\n2. �����ϱ�\n3. ����&��� Ȯ��\n4. ��������\n");
	printf("��������������������\n");
	scanf("%d", &select);
	return select;
}

void register_login(USER user[10], int* index, int* player)
{
	int select;
	while (1)
	{
		printf("��������������������\n");
		printf("1. ȸ������\n2. �α���\n3. ���θ޴�\n");
		printf("��������������������\n");
		scanf("%d", &select);
		// ȸ������ �����Դϴ�.
		if (select == 1)
		{
			*index += 1;
			printf("���ӿ� ����� [���̵�]�� �����ּ���(�ִ� 15��): ");
			scanf("%s", user[*index].id);
			printf("���ӿ� ����� [��й�ȣ]�� �����ּ���(�ִ� 15��): ");
			scanf("%s", user[*index].pw);
			printf("���ӿ� ����� [�г���]�� �����ּ���: ");
			scanf("%s", user[*index].name);

			printf("���������� ȸ������ ó�� �Ǿ����ϴ�.\n");
		}
		// �α��� �����Դϴ�.
		if (select == 2)
		{
			char id[15], pw[15];
			int check;	// ID �ε��� Ȯ�ο� �����Դϴ�.
			int choice;

			while (1)
			{
				check = -1;
				// �α����� �� ������, ���θ޴��� ���� ������ ����ϴ�.
				printf("��������������������\n");
				printf("1. �α���\n2. ���θ޴�\n");
				printf("��������������������\n");
				scanf("%d", &choice);
				//
				if (choice == 1)
				{
					printf("ID �Է�: ");
					scanf("%s", id);
					printf("PW �Է�: ");
					scanf("%s", pw);
					for (int i = 0; i < 10; i++)
					{
						if (!strcmp(id, user[i].id))	// ���̵� ���� ���� Ȯ��
							check = i;
					}
					if (check >= 0)	// ���̵� ������ ���
					{
						if (!strcmp(pw, user[check].pw))	// ��й�ȣ ��ġ���� Ȯ��
						{
							printf("%s�� �α��� �Ǿ����ϴ�.\n", user[check].name);
							*player = check;
						}
						else
							printf("��й�ȣ�� Ʋ���ϴ�.\n");
					}
					else
						printf("�������� �ʴ� ���̵��Դϴ�.\n");
				}
				else break;
			}
		}
		else break;
	}
}

void rate_user(USER user[10], int player, int index)
{
	int select;
	while (1)
	{
		// ��α��� �Ͻ� �ݺ����� Ż���մϴ�.
		if (player == -1)
		{
			printf("���� �α����� ���ּ���.\n");
			break;
		}
		printf("��������������������\n");
		printf("1. ����&��� Ȯ��\n2. ���θ޴�\n");
		printf("��������������������\n");
		scanf("%d", &select);
		// ����&��� �����Դϴ�.
		if (select == 1)
		{
			//����� ����ϴ� �����Դϴ�.
			int win_box[10];	// ù��°���� �¸� Ƚ���� �����ɴϴ�.
			int index_box[10];	// �ε��� ����� �迭�Դϴ�.
			
			// ������ ��ŭ �ε����� 0���� ������������ �迭�մϴ�.
			for (int i = 0; i <= index; i++)
				index_box[i] = i;

			int temp, temp2;	// ��ȯ�ϱ� ���� �ӽ� �����Դϴ�.

			// �ε��������� �¸� Ƚ���� �迭�մϴ�.
			for (int i = 0; i <= index; i++)
							win_box[i] = user[i].rate[0];
			
			// �ε��� ������ �¸� Ƚ���� �������� �մϴ�.
			// �׸��� �ε��� ����� �迭�� ���� �ٲ��ݴϴ�.

			// �ΰ��� ���ؼ� ���������� �ϴ� ����� �̿��߽��ϴ�.
			for (int i = 0; i <= index - 1; i++)
			{
				for (int j = i + 1; j <= index; j++)
				{
					if (win_box[i] < win_box[j])
					{
						// �¸�Ƚ�� �迭�� ���������մϴ�.
						temp = win_box[j];
						win_box[j] = win_box[i];
						win_box[i] = temp;

						// ����� ���� �ε��� �迭�� �׿� ���� ���� ��迭�մϴ�.
						temp2 = index_box[j];
						index_box[j] = index_box[i];
						index_box[i] = temp2;
					}
				}
			}
			// ������ ����մϴ�.
			printf("��������������������\n");
			printf("�� %s ���� ���� ����: %d / ��: %d / ��: %d / ��: %d\n", user[player].name, user[player].rate[0], user[player].rate[1], user[player].rate[2], user[player].rate[3]);
			printf("��������������������\n");
			// ������ ����մϴ�.
			for (int i = 0; i <= index; i++)
			{
				printf("%2d.�� %s �� ��: %d / ��: %d / ��: %d / ��: %d\n", i + 1, user[index_box[i]].name, user[index_box[i]].rate[0], user[index_box[i]].rate[1], user[index_box[i]].rate[2], user[index_box[i]].rate[3]);
			}
			printf("��������������������\n");
		}
		else break;
	}
}

void file_load(FILE* fp, USER user[10], int* index)
{
	int i = 0;	// i ���� �߰�
	//�����͸� ���������� �����մϴ�.
	fseek(fp, 0, SEEK_SET);

	while (!feof(fp))
	{
		if (fread(&user[i], sizeof(USER), 1, fp) == 0)
		{
			--i;
			break;
		}
		else
		{
			i++;
			fseek(fp, -1, SEEK_CUR);
		}
		// ������ ������ Ȯ���ϱ� ���� 1byte��ŭ �о����Ƿ�
		// ���������͸� �ٽ� 1byte��ŭ ������ ������.
	}
	printf("[TEST] ���� �ε�����: %d\n", i);
	*index = i;
}

void file_save(USER user[10], int index)
{
	FILE* fp1 = fopen("data.dat", "wb");
	fseek(fp1, 0, SEEK_SET);
	for (int i = 0; i <= index; i++)
		fwrite(&user[i], sizeof(USER), 1, fp1);

	fclose(fp1);
}
