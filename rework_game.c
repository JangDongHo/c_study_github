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

int menu();	// 메뉴와 관련된 함수
void register_login(USER user[10], int* index, int* player);	// 회원가입&로그인 함수
/*void rate_user(USER user[10], int player, int index);	// 전적, 등수 함수
void main_game(USER user[10], int player);	// 게임 함수*/
void file_load(FILE* fp, USER user[10], int* index);	// 파일 불러오기
void file_save(USER user[10], int index);	// 파일 저장하기

int main()
{
	USER user[10];
	int index;	// 회원가입 된 유저의 수를 확인하는 변수입니다.
	int player;	// 로그인된 유저의 인덱스를 확인하는 변수입니다.

	// 파일의 존재 유무를 판단하는 구문입니다.
	FILE* fp;
	fp = fopen("data.dat", "rb");
	if (fp == NULL)
	{
		// 최초 실행 시 파일을 생성하는 구문입니다.
		printf("FILE DOWNLOAD (최초 1회)\n");
		fp = fopen("data.dat", "wb");
		for (int i = 0; i < 10; i++) {      //승,무,패,전을 0으로 초기화합니다.
			for (int j = 0; j < 4; j++) {
				user[i].rate[j] = 0;
			}
		}
		index = -1;	// index 값을 -1로 초기화합니다.
		printf("[TEST] 현재 인덱스값: %d\n", index);
	}
	else
	{
		file_load(fp, user, &index);	// index 값을 유저 수만큼 설정합니다.
	}
	fclose(fp);

	// 메뉴를 선택하는 구문입니다.
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
	printf("■■■■■■■■■■■■■■■■■■■\n");
	printf("1. 회원가입&로그인\n2. 게임하기\n3. 전적&등수 확인\n4. 게임종료\n");
	printf("■■■■■■■■■■■■■■■■■■■\n");
	scanf("%d", &select);
	return select;
}

void register_login(USER user[10], int* index, int* player)
{
	int select;
	while (1)
	{
		printf("■■■■■■■■■■■■■■■■■■■\n");
		printf("1. 회원가입\n2. 로그인\n3. 메인메뉴\n");
		printf("■■■■■■■■■■■■■■■■■■■\n");
		scanf("%d", &select);
		// 회원가입 구문입니다.
		if (select == 1)
		{
			*index += 1;
			printf("게임에 사용할 [아이디]를 정해주세요(최대 15자): ");
			scanf("%s", user[*index].id);
			printf("게임에 사용할 [비밀번호]를 정해주세요(최대 15자): ");
			scanf("%s", user[*index].pw);
			printf("게임에 사용할 [닉네임]을 정해주세요: ");
			scanf("%s", user[*index].name);

			printf("정상적으로 회원가입 처리 되었습니다.\n");
		}
		// 로그인 구문입니다.
		if (select == 2)
		{
			char id[15], pw[15];
			int check;	// ID 인덱스 확인용 변수입니다.
			int choice;

			while (1)
			{
				check = -1;
				// 로그인을 할 것인지, 메인메뉴로 나갈 것인지 물어봅니다.
				printf("■■■■■■■■■■■■■■■■■■■\n");
				printf("1. 로그인\n2. 메인메뉴\n");
				printf("■■■■■■■■■■■■■■■■■■■\n");
				scanf("%d", &choice);
				//
				if (choice == 1)
				{
					printf("ID 입력: ");
					scanf("%s", id);
					printf("PW 입력: ");
					scanf("%s", pw);
					for (int i = 0; i < 10; i++)
					{
						if (!strcmp(id, user[i].id))	// 아이디 존재 여부 확인
							check = i;
					}
					if (check >= 0)	// 아이디가 존재할 경우
					{
						if (!strcmp(pw, user[check].pw))	// 비밀번호 일치여부 확인
						{
							printf("%s님 로그인 되었습니다.\n", user[check].name);
							*player = check;
						}
						else
							printf("비밀번호가 틀립니다.\n");
					}
					else
						printf("존재하지 않는 아이디입니다.\n");
				}
				else break;
			}
		}
		else break;
	}
}

void file_load(FILE* fp, USER user[10], int* index)
{
	int i = 0;	// i 변수 추가
	//포인터를 시작점으로 지정합니다.
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
		// 파일의 끝인지 확인하기 위해 1byte만큼 읽었으므로
		// 파일포인터를 다시 1byte만큼 앞으로 돌린다.
	}
	printf("[TEST] 현재 인덱스값: %d\n", i);
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
