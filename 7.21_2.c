#include <stdio.h>
#include <string.h>
#define SIZE 100

struct person {
	char name[SIZE][30];		// 이름
	char phone[SIZE][30];		// 휴대폰
} PERSON;

int index = 0;	// 증감 변수

void menu();
void add_record();
void search_record();
void print_all();
void delete_record();

void main()
{
	int select;
	while (1)
	{
		menu();		// 메뉴를 표시한다
		printf("Choose the item: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1: add_record(); break;	// 데이터를 추가한다
		case 2: delete_record(); break;	// 데이터를 삭제한다
		case 3: search_record(); break;	// 데이터를 탐색한다
		case 4: print_all();  break;		// 데이터를 모두 출력한다
		case 5: printf("프로그램을 종료합니다.\n");  exit(1);
		}
	}
}

// 메뉴를 화면에 표시하는 함수
void menu()
{
	printf("***** MENU *****\n");
	printf(" 1. Insert\n 2. Delete\n 3.Search\n 4. Print All\n 5. Exit\n");
}

// 데이터를 추가한다
void add_record()
{
	printf("[ INSERT ]\n");
	printf("Input Name: ");
	scanf("%s", PERSON.name[index]);
	printf("Input Tel Number: ");
	scanf("%s", PERSON.phone[index]);
	index++;
}

// 데이터를 탐색한다
void search_record()
{
	char name[30];

	printf("Search Name: ");
	scanf("%s", name);

	for (int i = 0; i < index; i++)
	{
		if (strcmp(PERSON.name[i], name) == 0)
			printf("Name: %s  Phone: %s\n", PERSON.name[i], PERSON.phone[i]);
	}
}

void print_all()
{
	for(int i = 0;i<index;i++)
		printf("Name: %s  Phone: %s\n", PERSON.name[i], PERSON.phone[i]);
}

void delete_record()
{

}