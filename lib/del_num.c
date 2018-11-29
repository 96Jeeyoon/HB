int del_num(int **user, int check, int num)
{
	int i,j;
	for(i=0;i<num;i++) {
		for(j=0; j<num; j++) {
			if(check == user[i][j]) {
				user[i][j] == 88;
				return 0;
			}
		}
	}
	return 0;
}
