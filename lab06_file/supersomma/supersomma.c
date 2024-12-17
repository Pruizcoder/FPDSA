#include <stdio.h>
#include <stdlib.h>

int main()
{
   

}

void supersomma (char a[], char b[], char c[])
{
   int i_a, i_b, i_c, riporto, risultato_somma;

   i_a = strlen (a) - 1;
   i_b = strlen (b) - 1;

   i_c = (i_a > i_b) ? i_a : i_b;

   c[i_c+1] = '\0';

   riporto = 0;

   while ( ! (i_a < 0 && i_b < 0) )
      {
      if (i_a >= 0 && i_b >= 0)
      {
         risultato_somma = (a[i_a] - '0') + (b[i_b] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';
         riporto = risultato_somma / 10;  
      }
      else if (i_a >= 0 && i_b < 0)
      {
         risultato_somma = (a[i_a] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0';   
         riporto = risultato_somma / 10;  
      }
      else
      {
         risultato_somma = (b[i_b] - '0') + riporto;
         c[i_c] = risultato_somma % 10 + '0'; 
         riporto = risultato_somma / 10;  
      }

      i_a--;
      i_b--;
      i_c--;
   }

}