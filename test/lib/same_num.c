#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int sam_num(int **user, int tmp, int num)
{
	int i,j;

	for(i=0; i<num; i++) {
		for(j=0; j<mum; j++) {
			if(user[i][j] == tmp) {
				return 1;
			}
		}
	}

	return 0;
}
