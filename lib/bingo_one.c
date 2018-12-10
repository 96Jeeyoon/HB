#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "myAlloc.h"
#include "check_bingo.h"
#include "input_num.h"
#include "del_num.h"
#include "init_bingo.h"

#include "win.h"

#define NUM 5

void bingo_one(int **user, int num, int mode)//PRACTICE MODE**********************
{
	int *check_arr, i, j, tmp, count = 0;

	user = myAlloc(num);
	check_arr = (int *)malloc((num*num) * sizeof(int));

	init_bingo(user, num); //set practice mode bingo...

	while (1)
	{
		system("clear");
		printf("\n\n\n");
		printf("**********PRACTICE MODE**********");
		printf("\n\n\n");

		for (i = 0; i<NUM; i++)
		{
			printf("|");
			for (j = 0; j<NUM; j++)
			{
				if (user[i][j] == 88) //ASCII 88 = 'X'
				{
					printf("%4c", user[i][j]);
				}
				else
				{
					printf("%4d", user[i][j]);
				}
			}
			printf("|\n");
		}

		if (check_bingo(user, num, mode))// check bingo. if retun value is not 0 then end the loop.
		{
			printf("\nYOU COMPLETED ONE BINGO!\n"); win();
			break;
		}

		if ((tmp = input_num(check_arr, num, &count, 1)) == 0)
			break;
		for (i = 0; i<(num*num); i++)
			del_num(user, check_arr[i], num);
	}
}
