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

int menu1();   //메인메뉴 
void menu2(USER user[10], int player);   //게임종료시 메뉴(다시하기,메뉴로)
int register_user(USER user[10], int index);   //회원가입함수
int login_user(USER user[10]);            //로그인함수
void rate_user(USER user[10], int n, int player, int index);      //전적관리, 등수
void  game_user(USER user[10], int player);   //게임화면
int game_result(int com, int choice1);        //게임 결과
int file_load(FILE* fp, USER user[10]);      //파일 불러오기
void file_save(USER user[10], int index);   //파일저장 메뉴



int main()
{
	USER user[10];
	for (int i = 0; i < 10; i++) {      //승,무,패,전 0으로 초기화
		for (int j = 0; j < 4; j++) {
			user[i].rate[j] = 0;
		}
	}
	int n;
	int index = -1;      //저장된 유저 수
	int player = 0;      //현재 플레이어 번호
	int file;

	FILE* fp;

	printf("파일을 불러오겠습니까?(1:O, 2:x)");
	scanf("%d", &file);
	if (file == 1)
	{
		fp = fopen("game.dat", "rb");
		if (fp == NULL) {
			printf("파일이 없습니다.");
			exit(1);
		}

		index = file_load(fp, user) - 1;
		fclose(fp);
	}


	while (1)
	{
		printf("\n%d\n", index);
		n = menu1();//--------------------------------
		switch (n) {//메뉴 선택
		case 1: {index = register_user(user, index); break; }   //1. 회원가입
		case 2: {player = login_user(user); break; }                  //2. 로그인
		case 3: case 4: {rate_user(user, n, player, index); break; }      //3. 전적 보기, 4. 등수 출력
		case 5: {game_user(user, player); break; }                  //5. 게임하기
		case 6: {file_save(user, index); return 0;    }                          //6. 종료
		}
	}
	file_save(user, index);
}

int menu1()
{
	int k;
	printf("*******MENU*******\n");
	printf("1. 회원가입\n2. 로그인\n3. 전적 보기\n4. 등수 출력\n5. 게임하기\n6. 종료\n");
	scanf("%d", &k);
	return k;
}
void menu2(USER user[10], int player)
{
	int choice2;
	printf("1.다시하기\n2.메인메뉴로\n");
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
	printf("게임에 사용할 [닉네임]을 정해주세요: ");
	scanf("%s", user[index].name);//--------------------------------------------------------------
	printf("게임에 사용할 [아이디]를 정해주세요: ");
	scanf("%s", user[index].id);
	printf("게임에 사용할 [비밀번호]를 정해주세요: ");
	scanf("%s", user[index].pw);

	printf("정상적으로 회원가입 처리 되었습니다.");
	printf("%s %s %s", user[index].name, user[index].id, user[index].pw);
	// index 값을 1 증가 시킵니다.


	return index;
	// 회원탈퇴 기능을 추가할 경우 index값을 재조정 하는 구문이 필요함. //
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

		for (int i = 0; i < 10; i++) // 아이디 존재여부 확인 
		{
			if (strcmp(id, user[i].id) == 0)  //아이디가 존재하지 않으면 k=-1
				k = i;
		}
		if (k >= 0)     //아이디가 존재할때
		{
			if (strcmp(pw, user[k].pw) == 0)   //비밀번호 일치여부 확인
			{
				printf("%s님 로그인 되었습니다.\n", user[k].name);
				return k;
			}
			else
			{
				printf("비밀번호가 틀립니다.\n");
			}
		}
		else
		{
			printf("존재하지 않는 아이디입니다.\n");
		}



	}
}

void rate_user(USER user[10], int n, int player, int index)
{
	if (n == 3)	// 만약 3번(전적)을 입력했을 경우
	{
		printf("***************");
		printf("【 %s 님의 전적 】승: %d / 패: %d / 무: %d / 전: %d\n", user[player].name, user[player].rate[0], user[player].rate[1], user[player].rate[2], user[player].rate[3]);
		printf("***************");
	};

	if (n == 4)	// 만약 4번(등수)을 입력했을 경우
	{
		int win_box[10];// 첫번째 부터 승 횟수를 가져옴
		int index_box[10];  //01234455...

		for (int i = 0; i <= index; i++)
		{
			index_box[i] = i;
		}

		int temp, temp2;	// 임시 변수

		// 인덱스순으로 승리 수를 배열합니다.
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
			printf("%2d.【 %s 】 승: %d / 패: %d / 무: %d / 전: %d\n", i + 1, user[index_box[i]].name, user[index_box[i]].rate[0], user[index_box[i]].rate[1], user[index_box[i]].rate[2], user[index_box[i]].rate[3]);
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
	printf("1.가위\t2.바위\t3.보\t");
	scanf("%d", &choice1);

	/*if (choice1 == 4) {
		menu2(user, player);
	}*/

	//else {
	user[player].rate[3]++;
	printf("COM vs USER: %s\n결과", user[player].name);
	result = game_result(com, choice1);
	switch (result) {
	case 0: {printf("승\n"); user[player].rate[0]++; break; }
	case 1: {printf("패\n"); user[player].rate[1]++; break; }
	case 2: {printf("무\n"); user[player].rate[2]++; break; }
	}
	menu2(user, player);
	//}
	//----------------------------------------------------------------------
}
// 승->0, 패->1, 무->2 반환
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
	int i = 0;        //i변수 추가
	/*char user_name[10];
	printf("찾고자하는 이름을 입력하세요: ");
	scanf("%s", user_name);*/
	fseek(fp, 0, SEEK_SET);

	while (!feof(fp)) {  //------------------------------------
		//fseek(fp, 0, SEEK_SET);  계속 첫번째서 시작함 
		fread(&user[i], sizeof(USER), 1, fp);  //이거도 ..........
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

