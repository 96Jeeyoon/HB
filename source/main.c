#include "baseball.h"
#include "baseball_hard.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int mode_num;
	printf("1. Baseball game_easy mode.\n");
	printf("2. Baseball game_hard mode.\n");
	
	scanf("%d",&mode_num);

	if(mode_num == 1) {
		baseball();
	}

	else if(mode_num == 2){
		baseball_hard();
	}

	else {
		printf("only enter 1 or 2");	
	}	
	return 0;
}
