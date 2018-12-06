#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>


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

