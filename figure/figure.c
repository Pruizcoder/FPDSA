#include <stdio.h>
#include <stdlib.h>

void linea();
void quadrato();
void triangolo ();



int main()
{
   char input;
   printf("inserisci la sequenza di caratteri");
   input = getchar();
   while (getchar() != '\n')
   {
      switch (input)
      {
      case 'Q':
      case 'q':
         // funzione quadrato
         break;
      case 'L':
      case 'l':
            //funzione linea
         break;
      case 't':
      case 'T':
      // funzione triangolo
      default:
            }
   }
   return EXIT_SUCCESS;
}

void linea()
{
   char l;
   l = getchar();
   l = l - 48;
   for (int i = 0; i < l; i++)
   {
      printf('*');
   }
   
}
void quadrato()
{
 
   char l;
   l = getchar();
   l = l - 48;
   for (int i = 0; i < l; i++)
   {
      
   }
   
  
     
}