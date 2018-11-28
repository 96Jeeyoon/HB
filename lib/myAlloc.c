#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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
