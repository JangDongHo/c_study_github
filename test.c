#include <stdio.h>
#define CREAM 500
#define SAEWOO 700
#define COKE 400

void main()
{
	int money;
	int cr, sa, co;
	int check = 0;

	printf("���� ����� �����ϰ� �ִ� �ݾ� : ");
	scanf("%d", &money);

	for (cr = 1; cr*CREAM < money; cr++)
	{
		for (sa = 1; sa*SAEWOO < money; sa++)
		{
			for (co = 1; co*COKE < money; co++)
			{
				if ((cr * CREAM + sa * SAEWOO + co * COKE) == money)
				{
					printf("ũ���� %d��, ����� %d��, �� �� %d��\n", cr, sa, co);
					co = 1;
					break;
				}
			}
		}
	}


}
