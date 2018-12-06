#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define NUM 5

#include "myAlloc.h"
#include "check_bingo.h"
#include "input_num.h"
#include "del_num.h"
#include "init_bingo.h"

#include "win.h"

void two(int **user, int **com, int num, int mode)
{
	int *check_arr;
	int i, tmp, count = 0;

	user = myAlloc(num);
	com = myAlloc(num);

	check_arr = (int *)malloc((num*num) * sizeof(int));

	init_bingo(user, num);
	init_bingo(com, num);

	while (1)
	{
		system("clear");
		//printf("\n Computer Choose (%d)\n", tmp);
		printf("\n\n\n\t[user]\t\t\t\t[computer]\n\n\n");
		for (int i = 0; i < 5; i++)
		{
			printf("|");
			for (int j = 0; j < 5; j++)
			{
				if (user[i][j] == 88)
					printf("%4c", user[i][j]); // X
				else
					printf("%4d", user[i][j]); // number
			}
			printf("   |\t |");

			for (int j = 0; j < 5; j++)
			{
				if (com[i][j] == 88)
					printf("%4c", com[i][j]); // X
				else
					printf("%4d", com[i][j]); // number
			}
			printf("   |\n|\t\t\t| \t |\t\t\t |\n");
		}

		//bingo check-win,lose

		printf("\nYOU MADE %d BINGO!\n",check_bingo(user, num, mode));

		printf("\nCOMPUTER MADE %d BINGO!\n",check_bingo(com, num, mode));





		if (check_bingo(user, num, mode) == 5)
		{
			printf("\nyour win.\n"); win();
			break;
		}
		if (check_bingo(com, num, mode) == 5)
		{
			printf("\ncomputer win.\n");
			break;
		}

		if ((tmp = input_num(check_arr, num, &count, 1)) == 0)
			break;

		for (i = 0; i<(num*num); i++)
		{
			del_num(user, check_arr[i], num);
			del_num(com, check_arr[i], num);
		}

		system("clear");
		//printf("\n Computer Choose (%d)\n", tmp);
		printf("\n\n\n\t[user]\t\t\t\t[computer]\n");
		for (int i = 0; i < 5; i++){
			printf("|");
			for (int j = 0; j < 5; j++)
			{
				if (user[i][j] == 88)
					printf("%4c", user[i][j]); // X
				else
					printf("%4d", user[i][j]); // number
			}
			printf("    |\t |");

			for (int j = 0; j < 5; j++)
			{
				if (com[i][j] == 88)
					printf("%4c", com[i][j]); // X
				else
					printf("%4d", com[i][j]); // number
			}
			printf("   |\n");
		}

		tmp = input_num(check_arr, num, &count, mode);
		printf("\n Computer Choose (%d)", tmp);

		for (i = 0; i<(num*num); i++)
		{
			del_num(user, check_arr[i], num);
			del_num(com, check_arr[i], num);
		}

		fflush(stdin);
		getchar();
	}
}

