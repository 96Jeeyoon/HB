#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int same_num(int **user, int tmp, int num)
{
	int i, j;

	for (i = 0; i<num; i++) {
		for (j = 0; j<num; j++) {
			if (user[i][j] == tmp) {
				return 1;
			}
		}
	}

	return 0;
}
