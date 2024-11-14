#include <stdio.h>
#include <stdlib.h>

void linea(char l);
void quadrato(char l);
void triangolo (char l);



int main()
{
   char input = 0;
   char n = 0;
   //printf("inserisci la sequenza di caratteri\n");
   while ((input=getchar()) != '\n')
   {
      n = getchar();
      n = n - '0';
      if ((n<1) || (n>9))
      {
         return EXIT_FAILURE;
      }
      


      switch (input)
      {
      case 'Q':
      case 'q':
        quadrato (n);
        
         break;
      case 'L':
      case 'l':
            linea(n);
            
         break;
      case 't':
      case 'T':
            triangolo(n);
            
      default:
            return EXIT_FAILURE;
            }
            printf("\n");
            
   }
   return EXIT_SUCCESS;
}

void linea(char l)
{
   for (int i = 0; i < l; i++)
   {
      printf("*");
   }
      printf("\n");
   
}
void quadrato(char l)
{
   for (int i = 0; i < l; i++)
   {
      linea(l);
   }
   
  
     
}

void triangolo (char l)
{
   for (int i = 0; i < l+1; i++)
   {
      linea(i);
   }
   
}