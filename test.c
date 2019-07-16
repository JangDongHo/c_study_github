#include <stdio.h>
#define CREAM 500
#define SAEWOO 700
#define COKE 400

void main()
{
	int money;
	int cr, sa, co;
		
	printf("당신이 가지고 있는 돈 (그지) : ");
	scanf("%d", &money);

	for (cr = 1; cr*CREAM < money; cr++)		// 크림 가격이 소유 돈보다 넘을때까지 반복
	{
		for (sa = 1; sa*SAEWOO < money; sa++)	// 새우 가격이 소유 돈보다 넘을때까지 반복
		{
			for (co = 1; co*COKE < money; co++)	// 콜라 가격이 소유 돈보다 넘을때까지 반복
			{
				if ((cr*CREAM + sa * SAEWOO + co * COKE) == money)	// 크림+새우+콜라 가격이 소유 돈이랑 일치할때 출력한다.
				{
					printf("크림빵 %d개, 새우깡 %d개, 콜 라 %d개\n", cr, sa, co);
					break;
				}
			}
		}
	}
}