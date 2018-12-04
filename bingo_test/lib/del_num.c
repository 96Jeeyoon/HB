#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int del_num(int **user, int check, int num)
{
	int i,j;
	for(i=0;i<num;i++) {
		for(j=0; j<num; j++) {
			if(check == user[i][j]) {
				user[i][j] == 'X';
				return 0;
			}
		}
	}
	return 0;
}
