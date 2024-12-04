#include <stdio.h>
#include <stdlib.h>
//#include <lib_string.h>


void nome_abbreviato(char *s, char *t);




#define MAX 32




int main()
{
   char s[MAX];
   char t[MAX];
   printf("inserisci cognome, nome;");
   fgets(t,MAX,stdin);
   nome_abbreviato(s,t);
   printf("%s", s);
   

   return EXIT_SUCCESS;

}

void nome_abbreviato(char *s, char *t)
{
   int i;
   int j=0;
   for ( i = 0; t[i] == ','; i++);
   i++;
   while (t[i]!= '\0')
   {
      if(t[i] == ' ')
      {
         i++;
         s[j] = t[i];
         j++;
         s[j] = '.';
         j++;
      }
      else
      {
         i++;
      }
      
   }
   for (int  k = 0; t[k] != ','; k++)
   {
      s[j]= t[k];
      j++;

   }


}

