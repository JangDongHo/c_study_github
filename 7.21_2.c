#include <stdio.h>
#include <string.h>
#define SIZE 100

struct person {
	char name[SIZE][30];		// �̸�
	char phone[SIZE][30];		// �޴���
} PERSON;

int index = 0;	// ���� ����

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
		menu();		// �޴��� ǥ���Ѵ�
		printf("Choose the item: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1: add_record(); break;	// �����͸� �߰��Ѵ�
		case 2: delete_record(); break;	// �����͸� �����Ѵ�
		case 3: search_record(); break;	// �����͸� Ž���Ѵ�
		case 4: print_all();  break;		// �����͸� ��� ����Ѵ�
		case 5: printf("���α׷��� �����մϴ�.\n");  exit(1);
		}
	}
}

// �޴��� ȭ�鿡 ǥ���ϴ� �Լ�
void menu()
{
	printf("***** MENU *****\n");
	printf(" 1. Insert\n 2. Delete\n 3.Search\n 4. Print All\n 5. Exit\n");
}

// �����͸� �߰��Ѵ�
void add_record()
{
	printf("[ INSERT ]\n");
	printf("Input Name: ");
	scanf("%s", PERSON.name[index]);
	printf("Input Tel Number: ");
	scanf("%s", PERSON.phone[index]);
	index++;
}

// �����͸� Ž���Ѵ�
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