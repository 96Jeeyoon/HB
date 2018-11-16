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

  while(1)
  {
    cnt++;
    printf("please enter 3 numbers/n");
    scanf("%d %d %d",&player[0],&player[1],&player[2]);

    if((player[0] == player[1]) || (player[1] == player[1]) || (player[2] == player[2]))
   {
     printf("no repeated number! One more/n");
     cnt--;
     continue;
   }

  }
}
