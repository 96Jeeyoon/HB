#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int menu();

int main()
{
   int **user, **com, mode, num = 5;
   srand(time(0));

   while(1)
   {
      mode = menu();
      switch(mode)
      {
        case 1 ://practice mode
           break;
        case 2 ://match mode
           break;
        case 3 ://end the game
           printf("\nGAME OVER\n"); 
           return 0;
      }
      system("pause");//print "Press any key to continue..."
      system("cls");//clear screen
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
