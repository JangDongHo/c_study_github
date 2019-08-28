#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>

typedef struct user
{
	char name[10];
	char id[10];
	char pw[10];
	int rate[4];
}USER;

int menu1();   //���θ޴� 
void menu2(USER user[10], int player);   //��������� �޴�(�ٽ��ϱ�,�޴���)
int register_user(USER user[10], int index);   //ȸ�������Լ�
int login_user(USER user[10]);            //�α����Լ�
void rate_user(USER user[10], int n, int player, int index);      //��������, ���
void  game_user(USER user[10], int player);   //����ȭ��
int game_result(int com, int choice1);        //���� ���
int file_load(FILE* fp, USER user[10]);      //���� �ҷ�����
void file_save(USER user[10], int index);   //�������� �޴�



int main()
{
	USER user[10];
	for (int i = 0; i < 10; i++) {      //��,��,��,�� 0���� �ʱ�ȭ
		for (int j = 0; j < 4; j++) {
			user[i].rate[j] = 0;
		}
	}
	int n;
	int index = -1;      //����� ���� ��
	int player = 0;      //���� �÷��̾� ��ȣ
	int file;

	FILE* fp;

	printf("������ �ҷ����ڽ��ϱ�?(1:O, 2:x)");
	scanf("%d", &file);
	if (file == 1)
	{
		fp = fopen("game.dat", "rb");
		if (fp == NULL) {
			printf("������ �����ϴ�.");
			exit(1);
		}

		index = file_load(fp, user) - 1;
		fclose(fp);
	}


	while (1)
	{
		printf("\n%d\n", index);
		n = menu1();//--------------------------------
		switch (n) {//�޴� ����
		case 1: {index = register_user(user, index); break; }   //1. ȸ������
		case 2: {player = login_user(user); break; }                  //2. �α���
		case 3: case 4: {rate_user(user, n, player, index); break; }      //3. ���� ����, 4. ��� ���
		case 5: {game_user(user, player); break; }                  //5. �����ϱ�
		case 6: {file_save(user, index); return 0;    }                          //6. ����
		}
	}
	file_save(user, index);
}

int menu1()
{
	int k;
	printf("*******MENU*******\n");
	printf("1. ȸ������\n2. �α���\n3. ���� ����\n4. ��� ���\n5. �����ϱ�\n6. ����\n");
	scanf("%d", &k);
	return k;
}
void menu2(USER user[10], int player)
{
	int choice2;
	printf("1.�ٽ��ϱ�\n2.���θ޴���\n");
	scanf("%d", &choice2);
	switch (choice2)
	{
	case 1: {game_user(user, player); break; }
	case 2:  break;//--------------------------------
	}
}

int register_user(USER user[10], int index)
{
	index += 1;
	printf("***************");
	printf("���ӿ� ����� [�г���]�� �����ּ���: ");
	scanf("%s", user[index].name);//--------------------------------------------------------------
	printf("���ӿ� ����� [���̵�]�� �����ּ���: ");
	scanf("%s", user[index].id);
	printf("���ӿ� ����� [��й�ȣ]�� �����ּ���: ");
	scanf("%s", user[index].pw);

	printf("���������� ȸ������ ó�� �Ǿ����ϴ�.");
	printf("%s %s %s", user[index].name, user[index].id, user[index].pw);
	// index ���� 1 ���� ��ŵ�ϴ�.


	return index;
	// ȸ��Ż�� ����� �߰��� ��� index���� ������ �ϴ� ������ �ʿ���. //
}

int login_user(USER user[10])
{
	char id[10], pw[10];
	int k = -1;

	while (1)
	{
		printf("id:");
		scanf("%s", id);
		printf("pw:");
		scanf("%s", pw);

		for (int i = 0; i < 10; i++) // ���̵� ���翩�� Ȯ�� 
		{
			if (strcmp(id, user[i].id) == 0)  //���̵� �������� ������ k=-1
				k = i;
		}
		if (k >= 0)     //���̵� �����Ҷ�
		{
			if (strcmp(pw, user[k].pw) == 0)   //��й�ȣ ��ġ���� Ȯ��
			{
				printf("%s�� �α��� �Ǿ����ϴ�.\n", user[k].name);
				return k;
			}
			else
			{
				printf("��й�ȣ�� Ʋ���ϴ�.\n");
			}
		}
		else
		{
			printf("�������� �ʴ� ���̵��Դϴ�.\n");
		}



	}
}

void rate_user(USER user[10], int n, int player, int index)
{
	if (n == 3)	// ���� 3��(����)�� �Է����� ���
	{
		printf("***************");
		printf("�� %s ���� ���� ����: %d / ��: %d / ��: %d / ��: %d\n", user[player].name, user[player].rate[0], user[player].rate[1], user[player].rate[2], user[player].rate[3]);
		printf("***************");
	};

	if (n == 4)	// ���� 4��(���)�� �Է����� ���
	{
		int win_box[10];// ù��° ���� �� Ƚ���� ������
		int index_box[10];  //01234455...

		for (int i = 0; i <= index; i++)
		{
			index_box[i] = i;
		}

		int temp, temp2;	// �ӽ� ����

		// �ε��������� �¸� ���� �迭�մϴ�.
		for (int i = 0; i <= index; i++)
			win_box[i] = user[i].rate[0];

		for (int i = 0; i <= index - 1; i++)
		{
			for (int j = i + 1; j <= index; j++)
			{
				if (win_box[i] < win_box[j])
				{
					temp = win_box[j];
					win_box[j] = win_box[i];
					win_box[i] = temp;

					temp2 = index_box[j];
					index_box[j] = index_box[i];
					index_box[i] = temp2;
				}
			}
		}

		for (int i = 0; i <= index; i++)
		{
			printf("***************");
			printf("%2d.�� %s �� ��: %d / ��: %d / ��: %d / ��: %d\n", i + 1, user[index_box[i]].name, user[index_box[i]].rate[0], user[index_box[i]].rate[1], user[index_box[i]].rate[2], user[index_box[i]].rate[3]);
			printf("***************");
		}
	};
}

void game_user(USER user[10], int player)
{
	srand((unsigned)time(NULL));
	int com = 1 + rand() % 3;

	int choice1;
	int result;
	//------------------------------------------------------------
	printf("1.����\t2.����\t3.��\t");
	scanf("%d", &choice1);

	/*if (choice1 == 4) {
		menu2(user, player);
	}*/

	//else {
	user[player].rate[3]++;
	printf("COM vs USER: %s\n���", user[player].name);
	result = game_result(com, choice1);
	switch (result) {
	case 0: {printf("��\n"); user[player].rate[0]++; break; }
	case 1: {printf("��\n"); user[player].rate[1]++; break; }
	case 2: {printf("��\n"); user[player].rate[2]++; break; }
	}
	menu2(user, player);
	//}
	//----------------------------------------------------------------------
}
// ��->0, ��->1, ��->2 ��ȯ
int game_result(int com, int choice1)
{
	if (com == choice1)
		return 2;
	else {
		switch (com) {
		case 1: if (choice1 == 2)return 0;
				else return 1; break;
		case 2:if (choice1 == 3)return 0;
			   else return 1; break;
		case 3:if (choice1 == 1)return 0;
			   else return 1; break;
		}
	}
}

int file_load(FILE* fp, USER user[10])
{
	//fp = fopen("game.dat", "r+");
	int i = 0;        //i���� �߰�
	/*char user_name[10];
	printf("ã�����ϴ� �̸��� �Է��ϼ���: ");
	scanf("%s", user_name);*/
	fseek(fp, 0, SEEK_SET);

	while (!feof(fp)) {  //------------------------------------
		//fseek(fp, 0, SEEK_SET);  ��� ù��°�� ������ 
		fread(&user[i], sizeof(USER), 1, fp);  //�̰ŵ� ..........
		i++;
	}
	return --i;
}

void file_save(USER user[10], int index)
{
	FILE* fp1 = fopen("game.dat", "wb");

	fseek(fp1, 0, SEEK_SET);

	for (int i = 0; i <= index; i++) {

		fwrite(&user[i], sizeof(USER), 1, fp1);

	}


	fclose(fp1);
}

