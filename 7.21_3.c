#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct person {
	char name[SIZE];		// �̸�
	char phone[SIZE];		// �޴���
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
	// ���� ������ �߰� ���� ����.
	if ((fp = fopen("phone.data", "a+")) == NULL)
	{
		fprintf(stderr, "ERROR CODE 01 - ���� ���� ����");
		exit(1);
	}
	while (1)
	{
		menu();		// �޴��� ǥ���Ѵ�
		printf("Choose the item: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1: add_record(fp); break;	// �����͸� �߰��Ѵ�
		case 2: delete_record(fp); break;	// �����͸� �����Ѵ�
		case 3: search_record(fp); break;	// �����͸� Ž���Ѵ�
		case 4: print_all(fp);  break;		// �����͸� ��� ����Ѵ�
		case 5: printf("���α׷��� �����մϴ�.\n");  exit(1);
		}
	}
	fclose(fp);		// ���� ������ �ݴ´�
}

// ����ڷκ��� �����͸� �޾Ƽ� ����ü�� ��ȯ�Ѵ�
PERSON get_record()
{
	PERSON data;

	getchar();		// �ٹٲ� ���� ���ֱ�
	printf("[ INSERT ]\n");
	printf("Input Name: "); gets_s(data.name, SIZE);	// �̸��� �Է¹޴´�
	printf("Input Tel Number: "); gets_s(data.phone, SIZE);	// �޴��� ��ȣ�� �Է¹޴´�
	return data;
}

// ����ü �����͸� ȭ�鿡 ����Ѵ�.
void print_record(PERSON data)
{
	printf("Name: %s  Tel: %s\n", data.name, data.phone);
}

// �޴��� ȭ�鿡 ǥ���ϴ� �Լ�
void menu()
{
	printf("***** MENU *****\n");
	printf(" 1. Insert\n 2. Delete\n 3.Search\n 4. Print All\n 5. Exit\n");
}

// �����͸� �߰��Ѵ�
void add_record(FILE* fp)
{
	PERSON data;
	data = get_record();	// ����ڷκ��� �����͸� �޾Ƽ� ����ü�� ����
	fseek(fp, 0, SEEK_END);	// ������ ������ ����
	fwrite(&data, sizeof(data), 1, fp);		// ����ü �����͸� ���Ͽ� ����
}

// �����͸� Ž���Ѵ�
void search_record(FILE* fp)
{
	char name[SIZE];
	PERSON data;

	fseek(fp, 0, SEEK_SET);		// ������ ó������ ����
	getchar();	// �ٹٲ� ���� ���ֱ�
	printf("Search Name: ");
	gets_s(name, SIZE);	// �̸��� �Է¹޴´�
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);	// ���� ��ġ���� �����͸� �д´�
		if (strcmp(data.name, name) == 0)
		{
			print_record(data);		// ��ġ�ϸ� �����͸� ȭ�鿡 ����Ѵ�
			break;
		}
	}
}

void print_all(FILE* fp)
{
	PERSON data;
	fseek(fp, 0, SEEK_SET);		// ������ ó������ ����
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		print_record(data);
	}
}

void delete_record(FILE* fp)
{
	printf("�ƾ�");
}
