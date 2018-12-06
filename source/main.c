#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>

#include "baseball_easy.h"
#include "baseball_hard.h"

#include "menu.h"
#include "myAlloc.h"
#include "check_bingo.h"
#include "init_bingo.h"
#include "one.h"
#include "two.h"
#include "del_num.h"
#include "input_num.h"
#include "same_num.h"

#include "win.h"

int main(void)
{
	
	system("pause");
	system("clear");

	int mode_num;
	printf("******************************************\n\n\n");
	printf("1. Baseball game_easy mode.\n");
	printf("2. Baseball game_hard mode.\n");
	printf("3. Bingo game.\n");
	printf("4. End this game.\n");
	printf("\n\n\n******************************************\n\n\n");

	scanf("%d",&mode_num);

	if(mode_num == 1) {
		baseball_easy();
	}

	else if(mode_num == 2){
		baseball_hard();
	}

	else if(mode_num ==3) {
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
				sleep(5); break;
			case 2://match mode
				two(user, com, num, mode);
				sleep(5); break;
			case 3://end the game
				printf("\nGAME OVER\n");
				return 0;
			}
			system("pause");//print "Press any key to continue..."
			system("clear");//clear screen
		}
	}

	else if(mode_num == 4){
		printf("\nGame Over\n");
		return 0;
	}

	else {
		printf("only enter 1 or 2");
	}
	return 0;
}



