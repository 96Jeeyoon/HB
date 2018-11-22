#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
  int answer[3];
  int player[3];
  int strike = 0, ball = 0;
  int i, j;
  int cnt = 0;

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

  printf("%d %d %d\n\n\n",answer[0],answer[1],answer[2]);


  printf("\n***GAME START***GAME START***GAME START***\n\n");



  while(1)
  {
     printf("%d time left\n",5-cnt);


     printf("please enter 3 numbers\n");
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
       printf("**********Congratulation!!!!!Wow!***********\n\n");
       int i,j;
       for( i = 4 ; i < 10; i +=2 )
       {
	  for( j = 0; j <= (10 - i); j++ ){printf(" ");}
          for( j = 0; j <= i * 2; j++ ){printf("%c",176);}
          for( j = 0; j <= (10 - i) * 2; j++ ){printf(" ");}
	  for( j = 0; j <= i * 2; j++ ){printf("%c",176);}
	  printf("\n");
       }
       for( i = 20; i >= 0; i -= 2 )
       {
          for( j = 0;  j <= 20 - i; j++ ){ printf(" ");} 
          for( j = 0; j <= i * 2; j++ ){printf("%c",176);}
          printf("\n");
       }
       printf("**********Congratulation!!!!!Wow!***********\n\n");
 
        break;
     }
     printf("%d strike %d ball \n\n", strike, ball);

     if(cnt == 5)
     {
       printf("\n***GAME OVER***GAME OVER***GAME OVER***\n");
       break;
     }

     strike  = 0;
     ball = 0;

   }
}
