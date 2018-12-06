#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

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


