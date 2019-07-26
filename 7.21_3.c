#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct person {
	char name[SIZE];		// 이름
	char phone[SIZE];		// 휴대폰
} PERSON;

void menu();
PERSON get_record();
void print_record(PERSON data);
void add_record(FILE* fp);
void search_record(FILE* fp);
void print_all(FILE* fp);
void delete_record(FILE* fp);

void main()
{
	FILE* fp;
	int select;
	// 이진 파일을 추가 모드로 연다.
	if ((fp = fopen("phone.data", "a+")) == NULL)
	{
		fprintf(stderr, "ERROR CODE 01 - 파일 열기 오류");
		exit(1);
	}
	while (1)
	{
		menu();		// 메뉴를 표시한다
		printf("Choose the item: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1: add_record(fp); break;	// 데이터를 추가한다
		case 2: delete_record(fp); break;	// 데이터를 삭제한다
		case 3: search_record(fp); break;	// 데이터를 탐색한다
		case 4: print_all(fp);  break;		// 데이터를 모두 출력한다
		case 5: printf("프로그램을 종료합니다.\n");  exit(1);
		}
	}
	fclose(fp);		// 이진 파일을 닫는다
}

// 사용자로부터 데이터를 받아서 구조체로 반환한다
PERSON get_record()
{
	PERSON data;

	getchar();		// 줄바꿈 문자 없애기
	printf("[ INSERT ]\n");
	printf("Input Name: "); gets_s(data.name, SIZE);	// 이름을 입력받는다
	printf("Input Tel Number: "); gets_s(data.phone, SIZE);	// 휴대폰 번호를 입력받는다
	return data;
}

// 구조체 데이터를 화면에 출력한다.
void print_record(PERSON data)
{
	printf("Name: %s  Tel: %s\n", data.name, data.phone);
}

// 메뉴를 화면에 표시하는 함수
void menu()
{
	printf("***** MENU *****\n");
	printf(" 1. Insert\n 2. Delete\n 3.Search\n 4. Print All\n 5. Exit\n");
}

// 데이터를 추가한다
void add_record(FILE* fp)
{
	PERSON data;
	data = get_record();	// 사용자로부터 데이터를 받아서 구조체에 저장
	fseek(fp, 0, SEEK_END);	// 파일의 끝으로 간다
	fwrite(&data, sizeof(data), 1, fp);		// 구조체 데이터를 파일에 쓴다
}

// 데이터를 탐색한다
void search_record(FILE* fp)
{
	char name[SIZE];
	PERSON data;

	fseek(fp, 0, SEEK_SET);		// 파일의 처음으로 간다
	getchar();	// 줄바꿈 문자 없애기
	printf("Search Name: ");
	gets_s(name, SIZE);	// 이름을 입력받는다
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);	// 현재 위치에서 데이터를 읽는다
		if (strcmp(data.name, name) == 0)
		{
			print_record(data);		// 일치하면 데이터를 화면에 출력한다
			break;
		}
	}
}

void print_all(FILE* fp)
{
	PERSON data;
	fseek(fp, 0, SEEK_SET);		// 파일의 처음으로 간다
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		print_record(data);
	}
}

void delete_record(FILE* fp)
{
	printf("아아");
}
