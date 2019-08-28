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
/*void rate_user(USER user[10], int player, int index);	// ����, ��� �Լ�
void main_game(USER user[10], int player);	// ���� �Լ�*/
void file_load(FILE* fp, USER user[10], int* index);	// ���� �ҷ�����
void file_save(USER user[10], int index);	// ���� �����ϱ�

int main()
{
	USER user[10];
	int index;	// ȸ������ �� ������ ���� Ȯ���ϴ� �����Դϴ�.
	int player;	// �α��ε� ������ �ε����� Ȯ���ϴ� �����Դϴ�.

	// ������ ���� ������ �Ǵ��ϴ� �����Դϴ�.
	FILE* fp;
	fp = fopen("data.dat", "rb");
	if (fp == NULL)
	{
		// ���� ���� �� ������ �����ϴ� �����Դϴ�.
		printf("FILE DOWNLOAD (���� 1ȸ)\n");
		fp = fopen("data.dat", "wb");
		for (int i = 0; i < 10; i++) {      //��,��,��,���� 0���� �ʱ�ȭ�մϴ�.
			for (int j = 0; j < 4; j++) {
				user[i].rate[j] = 0;
			}
		}
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
				/*case 2: {game_user(user, player); break; }
				case 3: {rate_user(user, player, index); break; }*/
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
