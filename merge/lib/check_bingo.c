#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int check_bingo(int **user, int num, int mode)
{
	int i, j, bingo = 0;
	int garo, sero, x_1 = 0, x_2 = 0;

	for (i = 0; i<num; i++)
	{
		garo = 0;

		for (j = 0; j<num; j++)
		{

			if (user[i][j] == 88)
				garo++;

			if (i == j)
			{
				if (user[i][j] == 88)
					x_1++;
			}
			if ((i + j) == 4)
			{
				if (user[i][j] == 88)
					x_2++;
			}
		}

		if (garo == 5)
		{
			bingo++;
			if (mode == 1) //if practice mode, game end 
				return bingo;
		}
	}

	for (j = 0; j<num; j++)
	{
		sero = 0;

		for (i = 0; i<num; i++)
			if (user[i][j] == 88)
				sero++;
		if (sero == 5)
		{
			bingo++;
			if (mode == 1)
				return bingo;
		}
	}

	bingo = bingo + (x_1 / 5) + (x_2 / 5);

	return bingo;
}
