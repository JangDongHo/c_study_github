#include <stdio.h>

void main()
{
	int	box[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%2d ", box[i][j]);
		printf("\n");
	}

	printf("======================\n");
	
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i >= 0; i--)
			printf("%2d ", box[i][j]);
		printf("\n");
	}

	printf("======================\n");

	for (int i = 3; i >= 0; i--)
	{
		for (int j = 3; j >= 0; j--)
			printf("%2d ", box[i][j]);
		printf("\n");
	}

	printf("======================\n");

	for (int j = 3; j >= 0; j--)
	{
		for (int i = 0; i < 4; i++)
			printf("%2d ", box[i][j]);
		printf("\n");
	}

	printf("======================\n");
}