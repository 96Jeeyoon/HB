#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int menu();
int** myAlloc(int num);
int sam_num(int **user, int tmp, int num);
int del_num(int **user, int check, int num);
int check_bingo(int **user, int num, int mode);
int input_num(int *check_ary, int num, int *count, int mode);

void init_bingo(int **init, int num);
void monitor(int **user, int **com, int num);
void one(int **user, int num, int mode);
void two(int **user, int **com, int num, int mode);

int main()
{
   system("clear");
   int **user, **com, mode, num = 5;
   srand(time(0));

   while(1)
   {
      mode = menu();
      switch(mode)
      {
        case 1 ://practice mode
	   one(user, num, mode); //user, num = 5, mode = 1
           break;
        case 2 ://match mode
	   two(user, com, num, mode);
           break;
        case 3 ://end the game
           printf("\nGAME OVER\n"); 
           return 0;
      }
      system("pause");//print "Press any key to continue..."
      system("clear");//clear screen
   }
   return 0;
}

int menu()
{
   int selmod;
   printf("\n\n\n\n\n");
   printf("*********************\n");
   printf("1. PRACTICE MODE\n\n");
   printf("2. MATCH MODE\n\n");
   printf("3. END THIS GAME :-( \n\n");
   printf("*********************\n");
   printf("\n\n\n");

   while(1)
   {
      printf("##ENTER THE MENU (1,2,3) : ");
      scanf("%d", &selmod);

      if(selmod>3 || selmod<1)
         printf("\nYOU ENTERED SOMETHING WRONG\n\n");
      else
         break;
   }

   return selmod;
}


void one(int **user, int num, int mode)//PRACTICE MODE**********************
{
   int *check_arr, i,j,tmp, count = 0;

   user = myAlloc(num);
   check_arr = (int *)malloc((num*num) * sizeof(int));

   init_bingo(user, num); //set practice mode bingo...

   while(1)
   {
      system("clear");
      printf("\n\n\n");
      printf("**********PRACTICE MODE**********");
      printf("\n\n\n");

      for(i=0; i<num; i++)
      {
         printf("|");
         for(j=0; j<num; j++)
         {
            if(user[i][j] == 88) //ASCII 88 = 'X'
            {
               printf("%4c",user[i][j]);
            }
            else
            {
               printf("%4d",user[i][j]);
            }
         }
         printf("|\n");
      }
      
      if(check_bingo(user, num, mode))// check bingo. if retun value is not 0 then end the loop.
      {
         printf("\nYOU COMPLETED ONE BINGO!\n");
         break;
      }
      
      if( (tmp = input_num(check_arr, num, &count, 1)) ==0 )
         break;
      for(i=0; i<(num*num); i++)
         del_num(user, check_arr[i], num);
   } 
}


void two(int **user, int **com, int num, int mode)
{
  int *check_arr;
  int i,tmp,count=0;

  user = myAlloc(num);
  com = myAlloc(num);

  check_arr = (int *)malloc((num*num) * sizeof(int));

  init_bingo(user,num);
  init_bingo(com,num);

  while(1)
  {
  	system("clear");
 	monitor(user,com,num);
	
	if(check_bingo(user, num, mode) == 5)
	{
	  printf("your win.");
          break;
	}
	if(check_bingo(com, num, mode) == 5)
	{
	  printf("computer win.");
          break;
	}

	if( (tmp = input_num(check_arr, num, &count, 1)) == 0 )
	   break;

	for(i=0; i<(num*num); i++)
	{
	   del_num(user, check_arr[i], num);
	   del_num(com, check_arr[i], num);
	}

	system("clear");
	monitor(user, com, num);

	tmp = input_num(check_arr, num, &count, mode);
	printf("\n Computer Choose (%d)",tmp);

	for(i=0; i<(num*num); i++)
	{
	   del_num(user, check_arr[i], num);
	   del_num(com, check_arr[i], num);
	}

	fflush(stdin);
	getchar();
  }
}


int** myAlloc(int num)
{
   int **tmp, i;
   tmp = (int **)malloc(num * sizeof(int *));
   for(i=0; i<num; i++)
   {
     tmp[i] = (int *)malloc(num * sizeof(int));
   }
   return tmp;
}

void monitor(int **user, int **com, int num) //bingo monitor print
{
   int i, j;

   printf("\n\t[user] \t\t\t\t [computer]\n");
   for(i=0; i<num; i++)
   {
      //user monitor
      printf("|");

      for(j=0; j<num; j++)
      {
          if(user[i][j] == 88)
              printf("%4c",user[i][j]); // X
          else
              printf("%4d",user[i][j]); // number
      }


      //computer monitor
      printf("   |\t   |");

      for(j=0; j<num; j++);
      {
         if(com[i][j] == 88)
              printf("%4c",com[i][j]);
         else
              printf("%4d",com[i][j]);
      }

      printf("   |\n");
   }
}


int input_num(int *check_arr, int num, int *count, int mode)
{
   int tmp, i;

   while(1)
   {
     if(mode ==1)//practice mode , user enter the number
     {
        printf("\n\n#PLEASE ENTER THE NUMBER TO ERASE!  [menu(0)] : ");
        scanf("%d", &tmp);
        if(tmp == 0)
        {
           printf("YOU SELECTED MENU.\n");
           break;
        }
     }
     else
        tmp = rand()%(num*num)+1;
     if(tmp>0 && tmp < (num*num)+1)
     {
        for(i=0; i<(num*num); i++)
        {
           if(check_arr[i] == tmp)
             break;
        }
        if(i == (num*num))
        {
           check_arr[(*count)++] = tmp;
           return tmp;
        }
        else
        {
           if(mode==1)
           printf("\n REPEATED NUMBER. PLEASE ENTER THE NUMBER AGAIN\n");

        }
 
     }
     else
     {
        fflush(stdin);
        printf("PLEASE ENTER THE NUMBER 1~%d \n\n",num*num);
     }
  }
  return tmp;
}


int check_bingo(int **user, int num, int mode)
{
   int i,j,bingo = 0;
   int garo, sero, x_1 =0, x_2=0;

   for(i=0; i<num; i++)
   {
      garo = 0;

      for(j=0; j<num; j++)
      {

          if(user[i][j] == 88)
             garo++;
   
          if(i==j)
          {
             if(user[i][j] == 88)
              x_1++;
          }
          if((i+j)==4)
          {
             if(user[i][j] == 88)
             x_2++;
          }
      }

      if(garo == 5)
      {
          bingo++;
          if(mode == 1) //if practice mode, game end 
            return bingo;
      }
   }

   for(j=0; j<num; j++)
   {
      sero = 0;

      for(i=0; i<num; i++)
         if(user[i][j] == 88)
           sero++;
      if(sero==5)
      {
         bingo++;
         if(mode==1)
           return bingo;
      }
   }

   bingo = bingo + (x_1 / 5) + (x_2 / 5);

   return bingo;
}

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

int sam_num(int **user, int tmp, int num)
{
	int i,j;

	for(i=0; i<num; i++) {
		for(j=0; j<num; j++) {
			if(user[i][j] == tmp) {
				return 1;
			}
		}
	}

	return 0;
}

void init_bingo(int **init, int num)
{
   int i, j, tmp;
   for(i = 0; i<num; i++)
   {
      for(j = 0; j<num; j++)
      {
         tmp = rand()%(num*num)+1;
         if(sam_num(init, tmp, num))
         {
            j--;
         }
         else
         {
            init[i][j] = tmp;
         }
      }
   }
}


