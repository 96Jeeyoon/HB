#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "win.h"
#include "lose.h"

void baseball_easy()
{

  system("pause");
  system("clear");

  int answer[3];
  int player[3];
  int strike = 0, ball = 0;
  int i, j;
  int cnt = 0;

  printf("Generating random numbers...\n\n");

  for (i = 0; i < 3; i++)
  {
    srand(time(NULL));
    answer[i] = rand() % 9 + 1;
    for ( j = 0; j < i; j++)
    {
      if(answer[i] == answer[j])
      {
        i--;
        break;
      }
    }

  }

  printf("The answer is %d %d %d\n\n\n",answer[0],answer[1],answer[2]);


  printf("\n***GAME START***GAME START***GAME START***\n\n");



  while(1)
  {

     printf("%d time left\n",10-cnt);

     printf("please enter 3 numbers : ");
     scanf("%d %d %d",&player[0],&player[1],&player[2]);

     if((player[0] == player[1]) || (player[1] == player[2]) || (player[0] == player[2]))
     {
       printf("no duplicated number! One more\n\n");
       //cnt--;
       continue;
     }

     if(player[0] == 0 || player[1] == 0 || player[2] == 0)
     {
       printf("Do not enter zero\n\n");
       //cnt--;
       continue;
     }

     cnt++;

     for(i = 0; i < 3; i++)
     {
       for(j = 0; j < 3; j++)
       {
          if(answer[i] == player[j] && i == j)
            strike++;
          if(answer[i] == player[j] && i != j)
            ball++;
       }
     }

     if(strike == 3)
     {
       win();
       break;
     } 
     printf("%d strike %d ball \n\n", strike, ball);
     
     if(cnt == 10)
     {
       printf("\n***GAME OVER***GAME OVER***GAME OVER***\n\n\n");

       lose();

       
       break;
     }

     strike  = 0;
     ball = 0;

   }
}
