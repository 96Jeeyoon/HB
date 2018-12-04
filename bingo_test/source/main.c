#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define NUM 5

#include "menu.h"
#include "myAlloc.h"
#include "check_bingo.h"
#include "init_bingo.h"
#include "one.h"
#include "two.h"
#include "del_num.h"
#include "input_num.h"
#include "same_num.h"

int main()
{
	system("clear");
	int **user, **com, mode, num = 5;
	srand(time(0));

	while (1)
	{
		mode = menu();
		//printf("%d", mode);
		switch (mode)
		{
		case 1://practice mode
			one(user, num, mode); //user, num = 5, mode = 1
			break;
		case 2://match mode
			two(user, com, num, mode);
			break;
		case 3://end the game
			printf("\nGAME OVER\n");
			return 0;
		}
		system("pause");//print "Press any key to continue..."
		system("clear");//clear screen
	}
	return 0;
}
