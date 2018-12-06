#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

void init_bingo(int **init, int num)
{
   int i, j, tmp;
   for(i = 0; i<num; i++)
   {
      for(j = 0; j<num; j++)
      {
         tmp = rand()%(num*num)+1;
         if(same_num(init, tmp, num))
         {
            j--;
         }
         else
         {
            init[i][j] = tmp;
         }
      }
}
