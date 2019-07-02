#include <stdio.h>
#define CREAM 500
#define SAEWOO 700
#define COKE 400

void main()
{
	int money;
	int cr, sa, co;
	int check = 0;

	printf("현재 당신이 소유하고 있는 금액 : ");
	scanf("%d", &money);

	for (cr = 1; cr*CREAM < money; cr++)
	{
		for (sa = 1; sa*SAEWOO < money; sa++)
		{
			for (co = 1; co*COKE < money; co++)
			{
				if ((cr * CREAM + sa * SAEWOO + co * COKE) == money)
				{
					printf("크림빵 %d개, 새우깡 %d개, 콜 라 %d개\n", cr, sa, co);
					co = 1;
					break;
				}
			}
		}
	}


}
