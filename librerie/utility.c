#include <stdio.h>
#include <stdlib.h>
#include "utility.h"


void swap (int *ptr_a, int *ptr_b)
{
   int t;

   t = *ptr_a;
   *ptr_a = *ptr_b;
   *ptr_b = t;

   return;
}

char minuscola (char ch)
{
   if (ch >= 'A' && ch <= 'Z')
      return ch - 'A' + 'a';
   else
      return ch;
}
