#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int input_num(int *check_arr, int num, int *count, int mode)
{
	int tmp, i;

	while (1)
	{
		if (mode == 1)//practice mode , user enter the number
		{
			printf("\n\n#PLEASE ENTER THE NUMBER TO ERASE!  [menu(0)] : ");
			scanf("%d", &tmp);
			if (tmp == 0)
			{
				printf("YOU SELECTED MENU.\n");
				break;
			}
		}
		else
			tmp = rand() % (num*num) + 1;
		if (tmp>0 && tmp < (num*num) + 1)
		{
			for (i = 0; i<(num*num); i++)
			{
				if (check_arr[i] == tmp)
					break;
			}
			if (i == (num*num))
			{
				check_arr[(*count)++] = tmp;
				return tmp;
			}
			else
			{
				if (mode == 1)
					printf("\n REPEATED NUMBER. PLEASE ENTER THE NUMBER AGAIN\n");

			}

		}
		else
		{
			fflush(stdin);
			printf("PLEASE ENTER THE NUMBER 1~%d \n\n", num*num);
		}
	}
	return tmp;
}
