
#include <stdio.h>
#include <stdlib.h>



int checkdate (int giorno, int mese, int anno);


int bisestile (int anno);


int giorni_del_mese (int mese, int anno);

void contagiorni(int g, int m, int a, int *contagiorni);

int main()
{
   //variablili di conteggio
   int totgiorni;
   //varaibili di input
   int g, m, a;

   printf ("Inserire la data (g m a): ");
   scanf ("%d %d %d", &g, &m, &a);

   if (checkdate (g, m, a))
      printf ("data corretta\n");
   else
      printf ("data errata\n");

   return EXIT_SUCCESS;
}


int checkdate (int giorno, int mese, int anno)
{
   
   if (anno > 1582)
   {
      
      if ((mese >= 1) && (mese <= 12))
      {
      
         if ((giorno > 0) && (giorno <= giorni_del_mese (mese, anno)))
         {
            return 1;
         }
      }
   }
   return 0;
}

int giorni_del_mese (int mese, int anno)
{
   switch (mese)
   {
   case 4:
   case 6:
   case 9:
   case 11:
      return 30;
      break;
   case 2:
      if (bisestile (anno))
            return 29;  
         else
            return 28;
   default:
      return 31;
      break;
   }
}
int bisestile (int anno)
{
   return ((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0); 
}


void contagiorni(int g, int m, int a, int *contagiorni)
{
   int mese = 1;
   while (mese<m)
   {
   contagiorni = contagiorni + giorni_del_mese(m,a);
   }
   contagiorni = contagiorni + g;

}