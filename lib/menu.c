#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int menu()
{
   int selmod;
   printf("\n\n\n\n******************************************\n\n\n\n");
   printf("\t  1. PRACTICE MODE\n\n");
   printf("\t  2. MATCH MODE\n\n");
   printf("\t  3. END BINGO GAME :-( \n");
   printf("\n\n\n******************************************\n\n\n");


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


