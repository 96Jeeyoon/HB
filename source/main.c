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
#include "bingo_one.h"
#include "bingo_two.h"
#include "del_num.h"
#include "input_num.h"
#include "same_num.h"

#include "win.h"
#include "lose.h"

int main(void)
{
	
	system("pause");
	system("clear");

	int mode_num;
	printf("\n\n\n\n******************************************\n\n\n\n");
	printf("\t1. Baseball game_easy mode.\n\n");
	printf("\t2. Baseball game_hard mode.\n\n");
	printf("\t3. Bingo game.\n\n");
	printf("\t4. End this game.\n");
	printf("\n\n\n******************************************\n\n\n");
	printf("ENTER THE NUMBER OF THE GAME : ");

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
				bingo_one(user, num, mode); //user, num = 5, mode = 1
				sleep(3); break;
			case 2://match mode
				bingo_two(user, com, num, mode);
				sleep(3); break;
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



